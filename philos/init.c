/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:57:00 by xjose             #+#    #+#             */
/*   Updated: 2024/10/24 09:10:12 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_arg(t_sys *sys, int argc, char **argv)
{
	sys->n_philos = ft_atoi(argv[1]);
	sys->nt_philos = ft_atoi(argv[1]);
	sys->t_die = ft_atoi(argv[2]);
	sys->t_eat = ft_atoi(argv[3]);
	sys->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		sys->n_eat = ft_atoi(argv[5]);
	else
		sys->n_eat = 0;
	sys->status = ON;
}

static void	init_mutex(t_sys *sys)
{
	int	i;

	pthread_mutex_init(&sys->print, NULL);
	sys->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* sys->n_philos);
	i = 0;
	while (i < sys->n_philos)
	{
		pthread_mutex_init(&sys->forks[i], NULL);
		i++;
	}
}

static void	init_philos(t_sys *sys)
{
	long long	start_time;
	int			i;

	i = 0;
	start_time = get_time_now();
	sys->philos = (t_philo *)malloc(sizeof(t_philo) * sys->n_philos);
	while (i < sys->n_philos)
	{
		sys->philos[i].start_time = start_time;
		sys->philos[i].id = i;
		sys->philos[i].eating = 0;
		sys->philos[i].last_meal = start_time;
		if (i == 0)
			sys->philos[i].left_fork = &sys->forks[sys->n_philos - 1];
		else
			sys->philos[i].left_fork = &sys->forks[i - 1];
		sys->philos[i].right_fork = &sys->forks[i];
		sys->philos[i].sys = sys;
		pthread_create(&sys->philos[i].thread, NULL, philo_routine,
			&sys->philos[i]);
		i++;
	}
}

void	init_sys(t_sys *sys, int argc, char **argv)
{
	init_arg(sys, argc, argv);
	init_mutex(sys);
	init_philos(sys);
}
