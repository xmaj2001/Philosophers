/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:30:09 by xjose             #+#    #+#             */
/*   Updated: 2024/09/24 20:12:44 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void start_system(t_system *sys)
{
    int i;

    i = 0;
    while (i < sys->nb_philo)
    {
        pthread_join(sys->philos[i].thread, NULL);
        i++;
    }
    free(sys->philos);
    free(sys->forks);
}

int main(int argc, char **argv)
{
    t_system sys;

    if (argc < 5 || argc > 6)
    {
        printf("Error: Invalid number of arguments\n");
        return (1);
    }
    init_system(&sys, argc, argv);
    start_system(&sys);
    return (0);
}