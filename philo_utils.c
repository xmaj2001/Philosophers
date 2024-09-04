/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:57:17 by xjose             #+#    #+#             */
/*   Updated: 2024/09/03 13:33:05 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	free_all(pthread_mutex_t *forks, t_philo *philo, int nbr_philo)
{
	int i;

	i = 0;
	while (i < nbr_philo)
		pthread_mutex_destroy(&forks[i++]);
	free(forks);
	free(philo);
}
