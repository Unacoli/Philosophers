/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:12:01 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/22 20:51:57 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_eat(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo[0].rules->eat_count <= 0)
		return (0);
	while (i < philo->rules->nbr_philo)
	{
		if (philo[i].nbr_eat != 0)
			return (-1);
	}
	return (1);
}

int	is_dead(t_philo *philo)
{
	if (get_time() - philo->last_eat > philo->rules->die_time)
	{
		*(philo->dead) = 1;
		philo_talk(philo, "died", philo->id);
		unlock_forks(philo);
		return (1);
	}
	return (0);
}
