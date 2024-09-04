/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:39:51 by xjose             #+#    #+#             */
/*   Updated: 2024/09/03 22:34:33 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	philo_thinking(t_philo *philo)
{
	if (philo->philo->did == 0)
		printf("[TIME:%dms] ",  get_time_in_ms() - philo->last_meal);printf("Filósofo \033[0;32m[%d] está pensando\033[0m\n", philo->id);
	philo->state = THINKING;
	return (philo->philo->did);
}

int	philo_take_forks(t_philo *philo)
{
	if (philo->id == 1)
	{
		pthread_mutex_lock(philo->fork_right);
		if (philo->philo->did == 0)
			printf("[TIME:%dms] ",  get_time_in_ms() - philo->last_meal);printf("Filósofo \033[0;33m[%d] pegou o garfo esquerdo\033[0m\n",
				philo->id);
		pthread_mutex_lock(philo->fork_left);
		if (philo->philo->did == 0)
			printf("[TIME:%dms] ",  get_time_in_ms() - philo->last_meal);printf("Filósofo \033[0;33m[%d] pegou o garfo direito\033[0m\n",
				philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->fork_left);
		if (philo->philo->did == 0)
			printf("[TIME:%dms] ",  get_time_in_ms() - philo->last_meal);printf("Filósofo \033[0;33m[%d] pegou o garfo esquerdo\033[0m\n",
				philo->id);
		pthread_mutex_lock(philo->fork_right);
		if (philo->philo->did == 0)
			printf("[TIME:%dms] ",  get_time_in_ms() - philo->last_meal);printf("Filósofo \033[0;33m[%d] pegou o garfo direito\033[0m\n",
				philo->id);
	}
	return (philo->philo->did);
}

int	philo_eating(t_philo *philo)
{
	if (philo->philo->did == 0)
	{
		printf("[TIME:%dms] ",  get_time_in_ms() - philo->last_meal);printf("Filósofo \033[0;34m[%d] está comendo\033[0m\n", philo->id);
		if (philo->eat == 1 && philo->eat_max > 0)
			philo->eat_max--;
		usleep(philo->time_to_eat * 1000);
		philo->state = EATING;
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
	}
	return (philo->philo->did);
}

int	philo_sleeping(t_philo *philo, long tmp_did)
{
	if (philo->philo->did == 0)
		printf("[TIME:%dms] ",  get_time_in_ms() - philo->last_meal);printf("Filósofo \033[0;36m[%d] está dormindo\033[0m\n", philo->id);
	usleep(philo->time_to_sleep * 1000);
	philo->state = SLEEPING;
	philo->time_to_die += tmp_did;
	if (philo->eat == 1 && philo->eat_max <= 0)
		return (1);
	return (philo->philo->did);
}

int	philo_died(t_philo *philo)
{
	long	did;

	did = (get_time_in_ms() - philo->last_meal);
	if (did >= philo->time_to_die)
		philo->philo->did = 1;
	philo->state = DIED;
	return (philo->philo->did);
}
