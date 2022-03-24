/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:16:16 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/24 19:01:54 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_talk(t_philo *philo, char *message, int id)
{
	if (one_dead(philo) == -1)
		return (-1);
	else
	{
		pthread_mutex_lock(philo->talk);
		printf("[%lli] %d %s\n", get_time() - philo->rules->init_time,
			id, message);
		pthread_mutex_unlock(philo->talk);
	}
	return (0);
}

long long	get_time(void)
{
	long long		time;
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	time = (temp.tv_sec * 1000) + (temp.tv_usec / 1000);
	return (time);
}

int	my_wait(int time, t_philo *philo)
{
	long long	wait;

	wait = get_time();
	while (get_time() - wait < time)
	{
		if (one_dead(philo))
			return (-1);
	}
	if (one_dead(philo))
		return (-1);
	return (0);
}

int	error(const char *str)
{
	printf("%s\n", str);
	return (EXIT_FAILURE);
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
	return (n * s);
}
