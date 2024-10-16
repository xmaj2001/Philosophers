/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:29:11 by xjose             #+#    #+#             */
/*   Updated: 2024/10/16 02:02:10 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	start_simulation(t_sys *sys)
{
	int	i;

	i = 0;
	pthread_create(&sys->death, NULL, monitor_death, sys);
	while (i < sys->n_philos)
	{
		pthread_join(sys->philos[i].thread, NULL);
		i++;
	}
	pthread_detach(sys->death);
	free(sys->philos);
	free(sys->forks);
}

int	main(int argc, char **argv)
{
	t_sys	sys;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	else if (is_valid_arg(argv[1]) == 0 || is_valid_arg(argv[2]) == 0
		|| is_valid_arg(argv[3]) == 0 || is_valid_arg(argv[4]) == 0
		|| (argc == 6 && is_valid_arg(argv[5]) == 0))
	{
		printf("Error: Invalid argument\n");
		return (1);
	}
	init_sys(&sys, argc, argv);
	start_simulation(&sys);
	return (0);
}
