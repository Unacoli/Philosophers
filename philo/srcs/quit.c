/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:17:00 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/24 21:57:04 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (-1);
}

static	void	free_mutex(t_philo *philo)
{
	if (philo)
	{
		pthread_mutex_destroy(philo->talk);
		free(philo->talk);
		pthread_mutex_destroy(philo->m_dead);
		free(philo->m_dead);
		pthread_mutex_destroy(philo->eat);
		free(philo->eat);
		pthread_mutex_destroy(philo->time);
		free(philo->time);
		if (philo->dead)
			free(philo->dead);
		free(philo);
	}
}

int	quit(t_rules *rules, pthread_mutex_t **forks, t_philo *philo, int ret)
{
	int	i;

	i = 0;
	if (forks)
	{
		while (i < rules->nbr_philo)
		{
			pthread_mutex_destroy(forks[i]);
			if (forks[i])
				free(forks[i]);
			i++;
		}
		free(forks);
	}
	free_mutex(philo);
	return (ret);
}
