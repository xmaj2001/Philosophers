/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:21:54 by xjose             #+#    #+#             */
/*   Updated: 2024/09/24 22:02:52 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"


void    *deadth_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if ((philo->id + 1) % 2 == 0)
		    usleep(philo->sys->time_to_eat * 1000);
    while (philo->sys->state == RUN)
    {
      is_dead(philo);
      usleep(5000);
    }
    return (NULL);
}



