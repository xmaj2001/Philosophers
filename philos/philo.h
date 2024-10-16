/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:49:00 by xjose             #+#    #+#             */
/*   Updated: 2024/10/16 01:55:17 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

enum				e_status
{
	ON,
	OFF
};

typedef struct s_sys
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	_Atomic int		status;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_t		death;
	struct s_philo	*philos;
}					t_sys;

typedef struct s_philo
{
	_Atomic long long	last_meal;
	int					id;
	_Atomic int			eating;
	int					is_dead;
	long long			start_time;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_t			thread;
	t_sys				*sys;
}					t_philo;

int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_strlen(const char *str);

void				init_sys(t_sys *sys, int argc, char **argv);
void				*philo_routine(void *arg);
void				*monitor_death(void *arg);

void				philo_thinking(t_philo *philo);
void				philo_pick_forks(t_philo *philo);
void				philo_eating(t_philo *philo);
void				philo_sleeping(t_philo *philo);
void				print_status(t_philo *philo, char *states);

long long			time_ms(t_philo *philo);
long long			get_time_now(void);
#endif
