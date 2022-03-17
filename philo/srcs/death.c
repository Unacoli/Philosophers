/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:12:01 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/17 16:24:15 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->rules->nbr_philo)
	{
		if (philo[i]->dead == 1)
			return (-1);
		i++;
	}
	return (0);
}
