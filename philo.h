/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:14:22 by xjose             #+#    #+#             */
/*   Updated: 2024/08/28 10:32:04 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "./ft_printf/ft_printf.h"

enum e_state
{
	NONE,
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
	int eat_count;
	pthread_mutex_t *fork_left;
	pthread_mutex_t *fork_right;
	pthread_t philo;
}	t_philo;

size_t	ft_strlen(const char *s);
void	ft_putstr(const char *s);
int		ft_atoi(const char *nptr);
#endif