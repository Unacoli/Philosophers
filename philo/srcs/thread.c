/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:15:39 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/30 15:30:21 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	thread_life(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	rules->init_time = get_time();
	while (i < rules->nbr_philo)
	{
		philo[i].last_eat = rules->init_time;
		if (pthread_create(&(philo[i].thread_id), NULL, &life, &(philo[i])))
			return (-1);
		i++;
	}
	return (0);
}

static void	lock(t_philo *philo)
{
	pthread_mutex_lock(philo->m_dead);
	*(philo->dead) = 1;
	pthread_mutex_unlock(philo->m_dead);
}

void	*base_thread(void *phil)
{
	t_philo	*philo;
	int		i;
	int		j;

	philo = phil;
	if (thread_life(philo->rules, philo))
		return (NULL);
	while (1)
	{
		if (all_eat(philo) == 1)
			lock(philo);
		i = -1;
		while (++i < philo->rules->nbr_philo)
		{
			if (is_dead(&(philo[i])))
			{
				j = -1;
				while (++j < philo->rules->nbr_philo)
					pthread_join(philo[j].thread_id, NULL);
				return (NULL);
			}
			i++;
		}
	}
	return (philo);
}
