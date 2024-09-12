/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:57:17 by xjose             #+#    #+#             */
/*   Updated: 2024/09/12 08:29:18 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

long long	get_time_now(void)
{
	struct timeval	timer;

	gettimeofday(&timer, NULL);
	return (timer.tv_sec * 1000 + timer.tv_usec / 1000);
}

long long	time_ms(t_philo *philo)
{
	return (get_time_now() - philo->sys->start_time);
}
void	print_states(t_philo *philo, char *states)
{
	long long	ms;

	pthread_mutex_lock(&philo->sys->system_mutex);
	ms = time_ms(philo);
	if (!philo->sys->system)
		printf("TIME[\033[0;33m%lld\033[0m] PHILO {%d} %s\t\n", ms, philo->id
			+ 1, states);
	pthread_mutex_unlock(&philo->sys->system_mutex);
}
