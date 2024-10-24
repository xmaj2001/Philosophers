/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:08:01 by xjose             #+#    #+#             */
/*   Updated: 2024/10/24 13:51:21 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->sys->n_eat == 0 || philo->eating < philo->sys->n_eat)
	{
		philo_death(philo);
		if (philo->sys->status == OFF)
			break ;
		philo_thinking(philo);
		philo_pick_forks(philo);
		philo_eating(philo);
		philo_sleeping(philo);
	}
	philo->sys->nt_philos--;
	return (NULL);
}

void	*monitor_death(void *arg)
{
	t_sys	*sys;
	int		i;

	sys = (t_sys *)arg;
	while (sys->nt_philos > 0)
	{
		i = 0;
		while (i < sys->n_philos)
		{
			if (get_time_now() - sys->philos[i].last_meal >= sys->t_die)
			{
				if ((sys->philos[i].eating != sys->n_eat))
				{
					print_status(&sys->philos[i], "\033[0;31mdied\033[0m");
					sys->status = OFF;
					return (NULL);
				}
			}
			i++;
		}
		usleep(1010);
	}
	return (NULL);
}
