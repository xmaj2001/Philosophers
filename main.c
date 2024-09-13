/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:26:41 by xjose             #+#    #+#             */
/*   Updated: 2024/09/13 09:42:40 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	system_start(t_sys *sys)
{
	int	i;

	i = 0;
	while (i < sys->nbr_philos)
		pthread_join(sys->philos[i++].philo, NULL);
	pthread_join(sys->task_death, NULL);
	i = 0;
	while (i < sys->nbr_philos)
		pthread_mutex_destroy(&sys->philos[i++].cheack);
	i = 0;
	while (i < sys->nbr_philos)
		pthread_mutex_destroy(&sys->forks[i++]);
	free(sys->philos);
	free(sys->forks);
	pthread_mutex_destroy(&sys->system_mutex);
}

int	main(int c, char *v[])
{
	t_sys	sys;
	int		i;

	i = 0;
	memset(&sys, 0, sizeof(t_sys));
	if (c != 5 && c != 6)
		return (1);
	init_system(&sys, c, v);
	system_start(&sys);
	return (0);
}
