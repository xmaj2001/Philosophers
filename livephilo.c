/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   livephilo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:33:47 by xjose             #+#    #+#             */
/*   Updated: 2024/09/03 22:36:52 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_in_ms(void)
{
	struct timeval	current_time;
	long			milliseconds;

	gettimeofday(&current_time, NULL);
	milliseconds = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (milliseconds);
}

void	*philo_live(void *data)
{
	t_philo	*philo;
	int		i;
	long	max_live;
	int		max_eat;

	philo = (t_philo *)data;
	i = 0;
	max_eat = 0;
	if (max_eat != philo->eat_max)
		max_eat = 1;
	philo->last_meal = get_time_in_ms();
	max_live = philo->time_to_die;
	while (philo->philo->did == 0)
	{
		if ((get_time_in_ms() - philo->last_meal) == philo->time_to_die)
		{
			philo_died(philo);
			philo->philo->did = 1;
			break ;
		}
		if (max_eat == 1)
		{
			if (philo->eat_max <= 0)
				break ;
			philo->eat_max--;
		}
		if (philo_thinking(philo) == 1)
			break ;
		if (philo_take_forks(philo) == 1)
			break ;
		if (philo_eating(philo) == 1)
			break ;
		if (philo_sleeping(philo, max_live) == 1)
			break ;
		// philo->time_to_die += max_live;
	}
	if (philo->fork_left)
		pthread_mutex_unlock(philo->fork_left);
	if (philo->fork_right)
		pthread_mutex_unlock(philo->fork_right);
	return (NULL);
}

void	*analyzing_philosophy(void *philo_date)
{
	t_philo	*philo;
	long	tmp_did;

	philo = (t_philo *)philo_date;
	tmp_did = philo->time_to_die;
	while (philo->philo->did == 0)
	{
		if (philo_died(philo) == 1)
			break ;
		if (philo_thinking(philo) == 1)
			break ;
		if (philo_take_forks(philo) == 1)
			break ;
		if (philo_eating(philo) == 1)
			break ;
		if (philo_sleeping(philo, tmp_did) == 1)
			break ;
	}
	if (philo->state == DIED && philo->philo->didx == 0)
	{	
		philo->philo->didx = 1;
		printf("[TIME:%dms] ",  get_time_in_ms() - philo->last_meal);printf("\033[0;31m[Filósofo] %d morreu 💀\033[0m\n", philo->id);
	}
	if (philo->fork_left)
		pthread_mutex_unlock(philo->fork_left);
	if (philo->fork_right)
		pthread_mutex_unlock(philo->fork_right);
	return (NULL);
}
