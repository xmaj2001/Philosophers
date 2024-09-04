/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states_log.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:07:31 by xjose             #+#    #+#             */
/*   Updated: 2024/09/03 13:51:17 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	log_thinking(t_philo *philo)
{
	if (philo->philo->did == 1)
		return ;
	printf("[Time:%dms]|\033[0;32m", get_time_in_ms() - philo->last_meal);
	printf("[Filósofo]%d está pensando", philo->id);
	printf("\033[0m\n");
}

void	log_forks(t_philo *philo, int fork)
{
	if (fork == 1)
	{
		if (philo->philo->did == 1)
			return ;
		printf("[Time:%dms]|\033[0;33m", get_time_in_ms() - philo->last_meal);
		printf("[Filósofo]%d pegou o garfo direito", philo->id);
		printf("\033[0m\n");
	}
	else
	{
		if (philo->philo->did == 1)
			return ;
		printf("[Time:%dms]|\033[0;33m", get_time_in_ms() - philo->last_meal);
		printf("[Filósofo]%d pegou o garfo esquerdo", philo->id);
		printf("\033[0m\n");
	}
}

void	log_eating(t_philo *philo)
{
	if (philo->philo->did == 1)
		return ;
	printf("[Time:%dms]|\033[0;34m", get_time_in_ms() - philo->last_meal);
	printf("[Filósofo]%d está comendo", philo->id);
	printf("\033[0m\n");
}

void	log_sleeping(t_philo *philo)
{
	if (philo->philo->did == 1)
		return ;
	printf("[Time:%dms]|\033[0;36m", get_time_in_ms() - philo->last_meal);
	printf("[Filósofo]%d está dormindo", philo->id);
	printf("\033[0m\n");
}

void	log_died(t_philo *philo)
{
	if (philo->philo->did == 1)
		return ;
	printf("[Time:%dms]|[\033[0;31m", get_time_in_ms() - philo->last_meal);
	printf("Filósofo]%d morreu", philo->id);
	printf("\033[0m\n");
}
