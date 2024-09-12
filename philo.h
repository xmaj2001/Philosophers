/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:27:37 by xjose             #+#    #+#             */
/*   Updated: 2024/09/12 09:53:57 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_sys
{
	int				nbr_philos;
	int				time_to_death;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_max_eat;
	int				system;
	int				count_philo_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	system_mutex;
	struct s_philo	*philos;
}					t_sys;

typedef struct s_philo
{
	int				id;
	int				nbr_eat;
	long long		last_time_eat;
	pthread_t		philo;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	cheack;
	struct s_sys	*sys;
}					t_philo;

void				init_system(t_sys *sys, int c, char *v[]);
void				init_thread(t_sys *sys);

void				*task_eat(void *data);
void				*task_death(void *data);
void				*philo_life(void *data);

void				print_states(t_philo *philo, char *states);

long long			get_time_now(void);
long long			time_ms(t_philo *philo);

int					ft_atoi(const char *nptr);
#endif
