/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:12:01 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/19 17:32:53 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_eat(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo[i])
	{
		if (philo[i]->nbr_eat != 0)
			return (-1);
	}
	return (1);
}

int	is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	if (all_eat(philo) != 1)
	{
		while (i < philo->rules->nbr_philo)
		{
			if (get_time() - philo[i].last_eat > philo->rules->die_time)
			{
				philo_talk(philo, "died", philo[i].id);
				return (-1);
			}
			i++;
		}
	}
	return (0);
}
