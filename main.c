/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 06:26:07 by xjose             #+#    #+#             */
/*   Updated: 2024/09/03 21:49:50 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int c, char *v[])
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	if (c == 5 || c == 6)
	{
		philos = malloc(sizeof(t_philo) * ft_atoi(v[1]));
		if (philos == NULL)
			exit(1);
		philos->did = 0;
		philos->didx = 0;
		forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(v[1]));
		if (forks == NULL)
			exit(1);
		init_forks(forks, ft_atoi(v[1]));
		init_philos(philos, ft_atoi(v[1]), forks, (t_args){c, v});
		i = 0;
		while (i < ft_atoi(v[1]))
		{
			pthread_join(philos[i++].thread, NULL);
		}
		free_all(forks, philos, ft_atoi(v[1]));
	}
	return (0);
}
