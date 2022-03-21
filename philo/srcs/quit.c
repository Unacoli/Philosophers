/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:17:00 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/21 02:56:40 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	quit(t_rules *rules, pthread_mutex_t **forks, t_philo *philo, int ret)
{
	int	i;

	i = 0;
	while (i < philo->rules->nbr_philo)
		pthread_join(philo[i].thread_id, NULL);
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
		free(philo);
	}
	return (ret);
}
