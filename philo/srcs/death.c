/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:12:01 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/30 15:58:08 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_eat(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->rules->eat_count <= 0)
		return (0);
	pthread_mutex_lock(philo->eat);
	while (i < philo->rules->nbr_philo)
	{
		if (philo[i].nbr_eat < philo->rules->eat_count)
		{
			pthread_mutex_unlock(philo->eat);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(philo->eat);
	return (1);
}

int	dead(t_philo *philo)
{
	pthread_mutex_lock(philo->m_dead);
	if (*(philo->dead))
	{
		pthread_mutex_unlock(philo->m_dead);
		return (-1);
	}
	pthread_mutex_unlock(philo->m_dead);
	return (0);
}

long long	mutex_time(t_philo *philo)
{
	long long	temp;

	pthread_mutex_lock(philo->time);
	temp = get_time() - philo->last_eat;
	pthread_mutex_unlock(philo->time);
	return (temp);
}

int	one_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->talk);
	if (dead(philo))
	{
		pthread_mutex_unlock(philo->talk);
		return (-1);
	}
	pthread_mutex_unlock(philo->talk);
	return (0);
}

int	is_dead(t_philo *philo)
{
	if (all_eat(philo) == 1)
		return (-1);
	if (mutex_time(philo) > philo->rules->die_time)
	{
		pthread_mutex_lock(philo->talk);
		*(philo->dead) = 1;
		printf("[%lli] %d %s\n", get_time() - philo->rules->init_time,
			philo->id, "died");
		pthread_mutex_unlock(philo->talk);
		return (-1);
	}
	return (0);
}
