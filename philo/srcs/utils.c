/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:16:16 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/17 16:18:59 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	long long		time;
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	time = (temp.tv_sec * 1000) + (temp.tv_usec / 1000);
	return (time);
}

void	my_wait(int time, t_philo *philo)
{
	long long	wait;

	wait = get_time() + time;
	while (get_time() < wait && is_dead(philo) != 1)
		usleep(time);
}

int	error(const char *str)
{
	printf("%s\n", str);
	return (EXIT_FAILURE);
}

static int	ft_if(int s)
{
	if (s > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	n;
	int				s;
	int				i;

	n = 0;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f') && str[i] != '\0')
		i++;
	s = 1;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (n > LONG_MAX)
		return (ft_if(s));
	return (n * s);
}
