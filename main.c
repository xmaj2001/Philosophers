/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:26:41 by xjose             #+#    #+#             */
/*   Updated: 2024/09/12 08:17:03 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	system_start(t_sys *sys)
{
	int i;

	i = 0;
	sys->start_time = get_time_now();
	while (i < sys->nbr_philos)
	{
		sys->philos[i].last_time_eat = sys->start_time;
		pthread_join(sys->philos[i].philo, NULL);
		pthread_mutex_destroy(&sys->philos[i].cheack);
		i++;
	}
	free(sys->philos);
	i = 0;
	while (i < sys->nbr_philos)
		pthread_mutex_destroy(&sys->forks[i++]);
	free(sys->forks);
}

int	main(int c, char *v[])
{
	t_sys		sys;
	int			i;

	i = 0;
	sys.nbr_philos = 0;
	if (c != 5 && c != 6)
		return (1);
	init_system(&sys, c, v);
	system_start(&sys);
	return (0);
}
