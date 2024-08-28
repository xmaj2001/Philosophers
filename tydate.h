/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tydate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:16:18 by xjose             #+#    #+#             */
/*   Updated: 2024/08/28 07:23:17 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef	struct	s_date
{
	int id;
	int eat;
	int time_eat;
	int time_sleep;
	int time_to_die;
	pthread_mutex_t *fork_right;
	pthread_mutex_t *fork_left;
	pthread_t philo;
	
} t_date;

