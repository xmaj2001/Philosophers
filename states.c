/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:39:51 by xjose             #+#    #+#             */
/*   Updated: 2024/09/02 19:50:36 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"

void philo_thinking(t_philo *philo)
{
    if(philo->philo->did == 0) printf("\033[0;32m[Filósofo] %d está pensando\033[0m\n", philo->id);
    philo->state = THINKING;
}

void philo_take_forks(t_philo *philo)
{
	if(philo->id == 1)
    {
    	pthread_mutex_lock(philo->fork_right);
    	if(philo->philo->did == 0) printf("\033[0;33m[Filósofo] %d pegou o garfo esquerdo\033[0m\n", philo->id);
		pthread_mutex_lock(philo->fork_left);
    	if(philo->philo->did == 0) printf("\033[0;33m[Filósofo] %d pegou o garfo direito\033[0m\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->fork_left);
    	if(philo->philo->did == 0) printf("\033[0;33m[Filósofo] %d pegou o garfo esquerdo\033[0m\n", philo->id);
    	pthread_mutex_lock(philo->fork_right);
    	if(philo->philo->did == 0) printf("\033[0;33m[Filósofo] %d pegou o garfo direito\033[0m\n", philo->id);
	}
}

void philo_eating(t_philo *philo)
{
   if(philo->philo->did == 0) 
   {
	printf("\033[0;34m[Filósofo] %d está comendo\033[0m\n", philo->id);
    usleep(philo->time_to_eat * 1000);
    philo->state = EATING;
    pthread_mutex_unlock(philo->fork_left);
    pthread_mutex_unlock(philo->fork_right);
   }
}

void philo_sleeping(t_philo *philo)
{
   if(philo->philo->did == 0) 
		printf("\033[0;36m[Filósofo] %d está dormindo\033[0m\n", philo->id);
	usleep(philo->time_to_sleep * 1000);
    philo->state = SLEEPING;
}

void philo_died(t_philo *philo)
{
   if(philo->philo->did == 0) 
   		printf("\033[0;31m[Filósofo] %d morreu 💀\033[0m\n", philo->id);
    philo->state = DIED;
}