/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:16:17 by xjose             #+#    #+#             */
/*   Updated: 2024/10/27 13:25:52 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_thinking(t_philo *philo)
{
	print_status(philo, "is thinking");
}

void	philo_pick_forks(t_philo *philo)
{
	if ((philo->id % 2) == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "\033[0;33mhas taken a fork\033[0m");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "\033[0;33mhas taken a fork\033[0m");
	}
	else
	{
		usleep(2000);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "\033[0;33mhas taken a fork\033[0m");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "\033[0;33mhas taken a fork\033[0m");
	}
}

void	philo_eating(t_philo *philo)
{
	philo->eating++;
	philo->last_meal = get_time_now();
	print_status(philo, "is eating");
	usleep(philo->sys->t_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->sys->t_sleep * 1000);
}

void	philo_death(t_philo *philo)
{
	if (philo->id == 0 && philo->sys->n_philos == 1)
	{
		print_status(philo, "is thinking");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "\033[0;33mhas taken a fork\033[0m");
		usleep(philo->sys->t_die * 1000);
		pthread_mutex_unlock(philo->left_fork);
		print_status(philo, "\033[0;31mdied\033[0m");
		philo->sys->status = OFF;
	}
}
