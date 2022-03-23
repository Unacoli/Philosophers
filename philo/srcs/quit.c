/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:17:00 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/23 02:42:20 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (-1);
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
	if (philo)
	{
		pthread_mutex_destroy(philo[0].talk);
		free(philo[0].talk);
		if (philo[0].dead)
			free(philo[0].dead);
		free(philo);
	}
	return (ret);
}
