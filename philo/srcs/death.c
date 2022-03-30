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
	while (i < philo->rules->nbr_philo)
	{
		if (philo[i].nbr_eat < philo->rules->eat_count)
			return (0);
		i++;
	}
	return (1);
}

int	one_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->talk);
	if (*(philo->dead))
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
	if (get_time() - philo->last_eat > philo->rules->die_time)
	{
		pthread_mutex_lock(philo->talk);
		pthread_mutex_lock(philo->var_lock);
		*(philo->dead) = 1;
		pthread_mutex_unlock(philo->var_lock);
		printf("[%lli] %d %s\n", get_time() - philo->rules->init_time,
			philo->id, "died");
		pthread_mutex_unlock(philo->talk);
		return (-1);
	}
	return (0);
}
