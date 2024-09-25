/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:36:43 by xjose             #+#    #+#             */
/*   Updated: 2024/09/24 22:32:48 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"


void	philo_state_thinking(t_philo *philo)
{
	if(is_dead(philo) == 1)
		return ;
	print_states(philo, "\033[0;32mis thinking\033[0m");
}

void	philo_state_pick_up_fork(t_philo *philo)
{
	if((philo->id + 1) % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_states(philo, "\033[0;33mpick up left fork\033[0m");
		pthread_mutex_lock(philo->right_fork);
		print_states(philo, "\033[0;33mpick up right fork\033[0m");
	}
	else
	{
		usleep(2000);
		pthread_mutex_lock(philo->right_fork);
		print_states(philo, "\033[0;33mpick up right fork\033[0m");
		pthread_mutex_lock(philo->left_fork);
		print_states(philo, "\033[0;33mpick up left fork\033[0m");
	}
}

void	philo_state_eating(t_philo *philo)
{
	if(is_dead(philo) == 1)
		return ;
	print_states(philo, "\033[0;34m eating\033[0m");
	x_usleep(philo,philo->sys->time_to_eat);
	philo->last_eat = get_time_now();
	philo->nb_eat += 1;
}

void	philo_state_sleeping(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (is_dead(philo) == 1)
		return ;
	print_states(philo, "\033[0;36mis sleeping\033[0m");
	x_usleep(philo, philo->sys->time_to_sleep);
}

void   *philo_routine(void *arg)
{
    t_philo *philo;
	// pthread_t       deadth_thread;

    philo = (t_philo *)arg;
	// pthread_create(&deadth_thread, NULL, deadth_routine, philo);
	// pthread_detach(deadth_thread);
    while (philo->sys->eat_count == -1 || philo->nb_eat < philo->sys->eat_count)
    {
		if(is_dead(philo) == 1)
			return (NULL);
        philo_state_thinking(philo);
		philo_state_pick_up_fork(philo);
		philo_state_eating(philo);
		philo_state_sleeping(philo);
		pthread_mutex_lock(&philo->sys->print_mutex);
		if (philo->sys->state == STOP)
		{
			pthread_mutex_unlock(&philo->sys->print_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->sys->print_mutex);
    }
    return (NULL);
}
