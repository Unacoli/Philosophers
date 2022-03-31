/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:45:44 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/24 21:58:43 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	last_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->time);
	philo->last_eat = get_time();
	pthread_mutex_unlock(philo->time);
}

static void	number_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->eat);
	(philo->nbr_eat)++;
	pthread_mutex_unlock(philo->eat);
}

static int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (philo_talk(philo, "has taken a fork", philo->id) == -1)
		return (pthread_mutex_unlock(philo->l_fork));
	pthread_mutex_lock(philo->r_fork);
	if (philo_talk(philo, "has taken a fork", philo->id) == -1)
		return (unlock_forks(philo));
	if (philo_talk(philo, "is eating", philo->id))
		return (unlock_forks(philo));
	last_eating(philo);
	if (my_wait(philo->rules->eat_time, philo))
		return (unlock_forks(philo));
	unlock_forks(philo);
	number_eat(philo);
	return (0);
}

static int	choose_eating(t_philo *philo)
{
	if (philo->id % 2)
	{
		if (eat(philo))
			return (-1);
	}
	else
	{
		if (mutex_time(philo) < philo->rules->eat_time / 5)
			if (my_wait(philo->rules->eat_time / 5, philo))
				return (-1);
		if (eat(philo))
			return (-1);
	}
	return (0);
}

void	*life(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	if (choose_eating(philo))
		return (NULL);
	while (1)
	{
		if (philo_talk(philo, "is sleeping", philo->id))
			return (NULL);
		if (my_wait(philo->rules->sleep_time, philo))
			return (NULL);
		if (philo_talk(philo, "is thinking", philo->id))
			return (NULL);
		if (eat(philo))
			return (NULL);
	}
	return (NULL);
}
