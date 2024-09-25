/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:17:33 by xjose             #+#    #+#             */
/*   Updated: 2024/09/24 22:33:29 by xjose            ###   ########.fr       */
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
	return (get_time_now() - philo->start_time);
}

void	print_states(t_philo *philo, char *states)
{
	pthread_mutex_lock(&philo->sys->print_mutex);
	if (philo->sys->state == RUN)
	{
		printf("TIME[\033[0;33m%lld\033[0m]", time_ms(philo));
		printf("\t{%d}\t%s\t\n", philo->id, states);
	}
	pthread_mutex_unlock(&philo->sys->print_mutex);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->sys->state_mutex);
    if ((get_time_now() - philo->last_eat) >= philo->sys->time_to_die && philo->sys->state == RUN)
    {
        print_states(philo, "CUBOU");
		philo->sys->state = STOP;
        pthread_mutex_unlock(&philo->sys->state_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->sys->state_mutex);
	return (0);
}
