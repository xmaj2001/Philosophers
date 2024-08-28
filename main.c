/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 06:26:07 by xjose             #+#    #+#             */
/*   Updated: 2024/08/28 14:23:14 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"


long get_time_in_ms(void) {
    struct timeval current_time;
	
    gettimeofday(&current_time, NULL);
    long milliseconds = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
    return milliseconds;
}


void *philo_live(void *date)
{
	t_philo *philo = (t_philo *)date;
	long start;

	start = get_time_in_ms();
	while (1)
	{
		if((get_time_in_ms() - start) >= philo->time_to_die)
		{
			philo->state = DIED;
			printf("%ld philo %d morreu\n",get_time_in_ms() - start, philo->id);
			return (NULL);
		}
		if (philo->state == THINKING)
			printf("%ld philo %d esta pensando\n",get_time_in_ms() - start, philo->id);
		if (philo->id == 1)
		{
			if((get_time_in_ms() - start) >= philo->time_to_die)
		{
			philo->state = DIED;
			printf("%ld philo %d morreu\n",get_time_in_ms() - start, philo->id);
			return (NULL);
		}
			pthread_mutex_lock(philo->fork_right);
			printf("%ld philo %d pegou o manbo direito\n",get_time_in_ms() - start,philo->id);
			if((get_time_in_ms() - start) >= philo->time_to_die)
		{
			philo->state = DIED;
			printf("%ld philo %d morreu\n",get_time_in_ms() - start, philo->id);
			return (NULL);
		}
			pthread_mutex_lock(philo->fork_left);
			if((get_time_in_ms() - start) >= philo->time_to_die)
		{
			philo->state = DIED;
			printf("%ld philo %d morreu\n",get_time_in_ms() - start, philo->id);
			return (NULL);
		}
			printf("%ld philo %d pegou o manbo esquerdo\n",get_time_in_ms() - start, philo->id);
			printf("%ld philo %d esta comendo\n",get_time_in_ms() - start, philo->id);
			philo->state = EATING;
			usleep(philo->time_to_eat * 1000);
			printf("%ld philo %d levantou\n",get_time_in_ms() - start, philo->id);
			philo->state = SLEEPING;
			if((get_time_in_ms() - start) >= philo->time_to_die)
		{
			philo->state = DIED;
			printf("%ld philo %d morreu\n",get_time_in_ms() - start, philo->id);
			return (NULL);
		}
			usleep(philo->time_to_sleep * 1000);
			printf("%ld philo %d foi ferra\n",get_time_in_ms() - start, philo->id);
			philo->state = THINKING;
			if((get_time_in_ms() - start) >= philo->time_to_die)
		{
			philo->state = DIED;
			printf("%ld philo %d morreu\n",get_time_in_ms() - start, philo->id);
			return (NULL);
		}
			pthread_mutex_unlock(philo->fork_left);
			pthread_mutex_unlock(philo->fork_right);
			philo->eat_count--;
			if (philo->eat_count <= 0)
				break;
		}
		else
		{
			pthread_mutex_lock(philo->fork_left);
			printf("%ld philo %d pegou o manbo esquerdo\n",get_time_in_ms() - start, philo->id);
			pthread_mutex_lock(philo->fork_right);
			printf("%ld philo %d pegou o manbo direito\n",get_time_in_ms() - start, philo->id);
			printf("%ld philo %d esta comendo\n",get_time_in_ms() - start, philo->id);
			philo->state = EATING;
			usleep(philo->time_to_eat * 1000);
			printf("%ld philo %d levantou\n",get_time_in_ms() - start, philo->id);
			philo->state = SLEEPING;
			usleep(philo->time_to_sleep * 1000);
			printf("%ld philo %d foi ferra\n",get_time_in_ms() - start, philo->id);
			philo->state = THINKING;
			pthread_mutex_unlock(philo->fork_left);
			pthread_mutex_unlock(philo->fork_right);
			philo->eat_count--;
			if (philo->eat_count <= 0)
				break;
		}
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
	int i;

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
