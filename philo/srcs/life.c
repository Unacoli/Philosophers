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

static int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->eat);
	pthread_mutex_lock(philo->l_fork);
	if (philo_talk(philo, "has taken a fork", philo->id) == -1)
		return (unlock_forks(philo));
	pthread_mutex_lock(philo->r_fork);
	if (philo_talk(philo, "has taken a fork", philo->id) == -1)
		return (unlock_forks(philo));
	pthread_mutex_unlock(philo->eat);
	if (philo_talk(philo, "is eating", philo->id))
		return (unlock_forks(philo));
	philo->last_eat = get_time();
	if (my_wait(philo->rules->eat_time, philo))
		return (unlock_forks(philo));
	pthread_mutex_lock(philo->var_lock);
	(philo->nbr_eat)++;
	pthread_mutex_unlock(philo->var_lock);
	unlock_forks(philo);
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
		if (get_time() - philo->last_eat < philo->rules->eat_time / 5)
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
