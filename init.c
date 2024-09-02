/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:21:55 by xjose             #+#    #+#             */
/*   Updated: 2024/09/02 19:11:05 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"

void init_forks(pthread_mutex_t *fork, int nbr_philo)
{
	int i;

	i = 0;
	while (i < nbr_philo)
		pthread_mutex_init(&fork[i++], NULL);
}

void init_philos(t_philo *philo, int nbr_philo, pthread_mutex_t *fork,t_args args)
{
	int i;
	
	i = 0;
	while (i < nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].state = THINKING;
		philo[i].time_to_die = ft_atoi(args.argv[2]);
		philo[i].time_to_eat = ft_atoi(args.argv[3]);
		philo[i].time_to_sleep = ft_atoi(args.argv[4]);
		if (args.argc == 6)
			philo[i].eat_max = ft_atoi(args.argv[5]);	
		else
			philo[i].eat_max = 0;
		philo[i].fork_left = &fork[i];
		philo[i].forks = fork;
		philo[i].philo = philo;
		philo[i].nbr_philo = nbr_philo;
		philo[i].fork_right = &fork[(i + 1) % nbr_philo];
		pthread_create(&philo[i].thread, NULL, philo_live, &philo[i]);
		i++;
	}
}
