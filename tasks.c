/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:33:47 by xjose             #+#    #+#             */
/*   Updated: 2024/09/13 10:32:56 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*task_eat(void *data)
{
	t_sys	*sys;

	sys = (t_sys *)data;
	while (!sys->system)
	{
		pthread_mutex_lock(&sys->system_mutex);
		if (sys->count_philo_eat == sys->nbr_philos)
			sys->system = 1;
		pthread_mutex_unlock(&sys->system_mutex);
		//usleep(1000);
	}
	return (NULL);
}

void	*task_death(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!philo->sys->system)
	{
		pthread_mutex_lock(&philo->sys->system_mutex);
		if (get_time_now() - philo->last_time_eat >= philo->sys->time_to_death
			&& philo->sys->system == 0)
		{
			printf("\033[0;31mTIME[%lld] PHILO (%d) %s\n", time_ms(philo),
				philo->id + 1, "CUBOU\033[0m");
			if (philo->right_fork)
				pthread_mutex_unlock(philo->right_fork);
			if (philo->left_fork)
				pthread_mutex_unlock(philo->left_fork);
			philo->sys->system = 1;
		}
		pthread_mutex_unlock(&philo->sys->system_mutex);
		//usleep(1000);
	}
	return (NULL);
}
