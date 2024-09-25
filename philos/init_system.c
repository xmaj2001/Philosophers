/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:11:49 by xjose             #+#    #+#             */
/*   Updated: 2024/09/24 22:32:37 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void init_args(t_system *sys, int argc, char **argv)
{
    sys->nb_philo = ft_atoi(argv[1]);
    sys->time_to_die = ft_atoi(argv[2]);
    sys->time_to_eat = ft_atoi(argv[3]);
    sys->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        sys->eat_count = ft_atoi(argv[5]);
    else
        sys->eat_count = -1;
}

static void init_mutex(t_system *sys)
{
    int i;

    i = 0;
    sys->forks = malloc(sizeof(pthread_mutex_t) * sys->nb_philo);
    while (i < sys->nb_philo)
    {
        pthread_mutex_init(&sys->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&sys->state_mutex, NULL);
    pthread_mutex_init(&sys->print_mutex, NULL);
}

static void init_philos(t_system *sys)
{
    int i;
    long long time;

    i = 0;
    time = get_time_now();
    sys->philos = malloc(sizeof(t_philo) * sys->nb_philo);
    while (i < sys->nb_philo)
    {
        sys->philos[i].id = i + 1;
        sys->philos[i].nb_eat = 0;
        sys->philos[i].sys = sys;
        sys->philos[i].start_time = time;
        sys->philos[i].last_eat = time;
        sys->philos[i].left_fork = &sys->forks[i];
        sys->philos[i].right_fork = &sys->forks[(i + 1) % sys->nb_philo];
        pthread_create(&sys->philos[i].thread, NULL, &philo_routine, &sys->philos[i]);
        i++;
    }
}

void init_system(t_system *sys, int argc, char **argv)
{
    sys->state = RUN;
    init_args(sys, argc, argv);
    init_mutex(sys);
    init_philos(sys);
}
