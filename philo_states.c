/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:39:51 by xjose             #+#    #+#             */
/*   Updated: 2024/09/13 08:59:50 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static void	philo_state_thinking(t_philo *philo)
{
	print_states(philo, "\033[0;32mis thinking\033[0m");
}

static void	philo_state_pick_up_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_states(philo, "\033[0;33mpick up left fork\033[0m");
	pthread_mutex_lock(philo->right_fork);
	print_states(philo, "\033[0;33mpick up right fork\033[0m");
}

static void	philo_state_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->cheack);
	philo->last_time_eat = get_time_now();
	pthread_mutex_lock(&philo->sys->system_mutex);
	if (!philo->sys->system)
		printf("TIME[\033[0;33m%lld\033[0m] PHILO {%d} %s\t\n", time_ms(philo), philo->id
			+ 1, "\033[0;36mis eating\033[0m");
	philo->nbr_eat += 1;
	if (philo->nbr_eat == philo->sys->nbr_max_eat)
		philo->sys->count_philo_eat += 1;
	pthread_mutex_unlock(&philo->sys->system_mutex);
	usleep(philo->sys->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->cheack);
}

static void	philo_state_sleeping(t_philo *philo)
{
	print_states(philo, "\033[0;36mis sleeping\033[0m");
	usleep(philo->sys->time_to_sleep * 1000);
}

void	*philo_life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(philo->sys->time_to_eat * 1000);
	while (!philo->sys->system)
	{
		philo_state_thinking(philo);
		philo_state_pick_up_fork(philo);
		philo_state_eating(philo);
		philo_state_sleeping(philo);
	}
	return (NULL);
}
