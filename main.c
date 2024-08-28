/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 06:26:07 by xjose             #+#    #+#             */
/*   Updated: 2024/08/28 13:15:32 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void *philo_live(void *date)
{
	t_philo *philo = (t_philo *)date;
	while (1)
	{
		if (philo->state == THINKING)
		{
			printf("philo %d esta pensando\n", philo->id);
			usleep(philo->time_to_die * 1000);
		}
		pthread_mutex_lock(philo->fork_left);
		printf("philo %d pegou o fork esquerdo\n", philo->id);
		pthread_mutex_lock(philo->fork_right);
		printf("philo %d pegou o fork direito\n", philo->id);
		printf("philo %d esta comendo\n", philo->id);
		philo->state = EATING;
		usleep(philo->time_to_eat * 1000);
		printf("philo %d levanta-se\n", philo->id);
		philo->state = SLEEPING;
		usleep(philo->time_to_sleep * 1000);
		printf("philo %d ira dormir\n", philo->id);
		philo->state = THINKING;
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		philo->eat_count--;
		if (philo->eat_count <= 0)
			break;
	}
}

void init_philo(t_philo *philo, pthread_mutex_t *fork, int c, char **v)
{
	int i;

	i = 0;
	while (i < ft_atoi(v[1]))
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	i = 0;
	while (i < ft_atoi(v[1]))
	{
		philo[i].id = i + 1;
		philo[i].state = THINKING;
		philo[i].time_to_die = ft_atoi(v[2]);
		philo[i].time_to_eat = ft_atoi(v[3]);
		philo[i].time_to_sleep = ft_atoi(v[4]);
		if (c == 6)
			philo[i].eat_count = ft_atoi(v[5]);
		else
			philo[i].eat_count = 1;
		philo[i].fork_left = &fork[i];
		philo[i].fork_right = &fork[(i + 1) % ft_atoi(v[1])];
		pthread_create(&philo[i].philo, NULL, &philo_live, &philo[i]);
		i++;
	}
}

void free_all(t_philo *philo, pthread_mutex_t *fork, int nbr_philo)
{
	int i;

	i = 0;
	while (i < nbr_philo)
	{
		pthread_mutex_destroy(philo[i].fork_left);
		pthread_mutex_destroy(philo[i].fork_right);
		i++;
	}
	free(philo);
	free(fork);
}

int main(int c, char *v[])
{
	t_philo *philo;
	pthread_mutex_t *fork;
	int	i;

	i = 0;
	if (c == 5 || c == 6)
	{
		philo = malloc(sizeof(t_philo) * ft_atoi(v[1]));
		if (philo == NULL)
			exit(1);
		fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(v[1]));
		if (fork == NULL)
			exit(1);
		init_philo(philo, fork, c, v);
		while (i < ft_atoi(v[1]))
		{
			pthread_join(philo[i].philo, NULL);
			i++;
		}
		free_all(philo, fork, ft_atoi(v[1]));
	}
	return 0;
}
