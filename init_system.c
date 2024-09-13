/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:21:55 by xjose             #+#    #+#             */
/*   Updated: 2024/09/13 08:48:04 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static void	init_args(t_sys *sys, int c, char *v[])
{
	sys->nbr_philos = ft_atoi(v[1]);
	sys->time_to_death = ft_atoi(v[2]);
	sys->time_to_eat = ft_atoi(v[3]);
	sys->time_to_sleep = ft_atoi(v[4]);
	if (c == 6)
		sys->nbr_max_eat = ft_atoi(v[5]);
	else
		sys->nbr_max_eat = 0;
	sys->system = 0;
	sys->count_philo_eat = 0;
}

static void	init_philos(t_sys *sys)
{
	int	i;

	i = 0;
	pthread_mutex_init(&sys->system_mutex, NULL);
	sys->philos = malloc(sizeof(t_philo) * sys->nbr_philos);
	if (sys->philos == NULL)
		return ;
	sys->forks = malloc(sizeof(pthread_mutex_t) * sys->nbr_philos);
	if (sys->forks == NULL)
		return ;
	sys->start_time = get_time_now();
	while (i < sys->nbr_philos)
	{
		sys->philos[i].id = i;
		sys->philos[i].nbr_eat = 0;
		sys->philos[i].last_time_eat = sys->start_time;
		pthread_mutex_init(&sys->forks[i], NULL);
		pthread_mutex_init(&sys->philos[i].cheack, NULL);
		if (i == 0)
			sys->philos[i].left_fork = &sys->forks[sys->nbr_philos - 1];
		else
			sys->philos[i].left_fork = &sys->forks[i - 1];
		sys->philos[i].right_fork = &sys->forks[i];
		sys->philos[i].sys = sys;
		i++;
	}
}

void	init_system(t_sys *sys, int c, char *v[])
{
	init_args(sys, c, v);
	init_philos(sys);
	init_thread(sys);
}

void	init_thread(t_sys *sys)
{
	int			i;
	pthread_t	task;
	pthread_t	thread_eat;

	i = 0;
	while (i < sys->nbr_philos)
	{
		pthread_create(&sys->philos[i].philo, NULL, philo_life,
			&sys->philos[i]);
		pthread_create(&sys->task_death, NULL, task_death, &sys->philos[i]);
		//pthread_detach(task);
		i++;
	}
	if (sys->nbr_max_eat != 0)
	{
		pthread_create(&thread_eat, NULL, task_eat, sys);
		pthread_detach(thread_eat);
	}
}
