/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:44:26 by xjose             #+#    #+#             */
/*   Updated: 2024/09/24 21:44:04 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	nbr;

	sign = 1;
	nbr = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
	{
		++nptr;
	}
	while (ft_isdigit(*nptr))
	{
		nbr = (nbr * 10) + (*nptr - '0');
		nptr++;
	}
	return (nbr * sign);
}

void	x_usleep(t_philo *philo, int time_x)
{
	int i;

	i = 0;
	while (i < (time_x / 10))
	{
		if (is_dead(philo) == 1)
			break;
		usleep(10000);
		i++;
	}
}
