/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   livephilo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:33:47 by xjose             #+#    #+#             */
/*   Updated: 2024/09/03 07:49:35 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"


long get_time_in_ms(void) 
{
	struct timeval current_time;
	long milliseconds;
	
	gettimeofday(&current_time, NULL);
	milliseconds = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (milliseconds);
}
void *philo_live(void *date)
{
	t_philo *philo = (t_philo *)date;
	int i;
	long	max_live;
	int max_eat;

	i = 0;
	max_eat = 0;
	if (max_eat != philo->eat_max)
		max_eat = 1;
	philo->last_meal = get_time_in_ms();
	max_live = philo->time_to_die;
	while (philo->philo->did == 0)
	{	
		if ((get_time_in_ms() - philo->last_meal) >= philo->time_to_die)
		{
			philo_died(philo);
			philo->philo->did = 1;
			break;
		}
		if(max_eat == 1)
		{
			if (philo->eat_max == 0)
				break;
			philo->eat_max--;
		}
		philo_thinking(philo);
		philo_take_forks(philo);
		philo_eating(philo);
		philo_sleeping(philo);
		philo->time_to_die += max_live;
	}
    usleep(1000);
	if (philo->fork_left)
    	pthread_mutex_unlock(philo->fork_left);
	if (philo->fork_right)
    	pthread_mutex_unlock(philo->fork_right);
	return (NULL);
}
