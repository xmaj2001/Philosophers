/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:04:43 by xjose             #+#    #+#             */
/*   Updated: 2024/09/24 22:33:25 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

enum e_system
{
    RUN,
    STOP
};
typedef struct s_system
{
    int				nb_philo;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				eat_count;
    enum e_system   state;
    struct s_philo  *philos;
    pthread_mutex_t	*forks;
    pthread_mutex_t state_mutex;
    pthread_mutex_t	print_mutex;
}				t_system;

typedef struct s_philo
{
    int				id;
    int				nb_eat;
    int              init;
    pthread_mutex_t	*left_fork;
    pthread_mutex_t	*right_fork;
    pthread_t        thread;
    long long	    start_time;
    long long	    last_eat;
    t_system		*sys;
}				t_philo;



void                *philo_routine(void *arg);
void				print_states(t_philo *philo, char *states);
void				*deadth_routine(void *arg);
void                init_system(t_system *sys, int argc, char **argv);
int	is_dead(t_philo *philo);
long long			get_time_now(void);
long long			time_ms(t_philo *philo);
int	                ft_atoi(const char *nptr);
void	x_usleep(t_philo *philo, int time_x);
#endif