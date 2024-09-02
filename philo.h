/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:14:22 by xjose             #+#    #+#             */
/*   Updated: 2024/09/02 19:47:29 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	DIED
};

typedef struct s_philo
{
	int id;
	enum e_state state;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	long last_meal;
	int did;
	int nbr_philo;
	pthread_mutex_t *forks;
	struct s_philo *philo;
	int eat_max;
	pthread_mutex_t *fork_left;
	pthread_mutex_t *fork_right;
	pthread_t thread;
}	t_philo;

typedef struct s_args
{
	int argc;
	char **argv;
}	t_args;


void init_forks(pthread_mutex_t *fork, int nbr_philo);
void init_philos(t_philo *philo, int nbr_philo, pthread_mutex_t *fork,t_args args);
void *philo_live(void *date);

void philo_thinking(t_philo *philo);
void philo_take_forks(t_philo *philo);
void philo_eating(t_philo *philo);
void philo_sleeping(t_philo *philo);
void philo_died(t_philo *philo);

long get_time_in_ms(void);
void	free_all(pthread_mutex_t *forks, t_philo *philo, int nbr_philo);
int		ft_atoi(const char *nptr);
#endif