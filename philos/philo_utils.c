/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:16:17 by xjose             #+#    #+#             */
/*   Updated: 2024/10/24 13:50:58 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_now(void)
{
	struct timeval	timer;

	gettimeofday(&timer, NULL);
	return (timer.tv_sec * 1000 + timer.tv_usec / 1000);
}

long long	time_ms(t_philo *philo)
{
	return (get_time_now() - philo->start_time);
}

void	print_status(t_philo *philo, char *states)
{
	pthread_mutex_lock(&philo->sys->print);
	if (philo->sys->status == ON)
	{
		printf("TIME[\033[0;33m%lld\033[0m]", time_ms(philo));
		printf("\t{%d}\t%s\t\n", philo->id + 1, states);
	}
	pthread_mutex_unlock(&philo->sys->print);
}
