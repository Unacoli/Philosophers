/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:45:44 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/16 19:17:42 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life(void *phil)
{
	t_philo	*philo;
	int		i;

	philo = phil;
	i = 0;
	while (i < philo->rules->nbr_philo)
	{
		printf("%d\n", philo[i].id);
		i++;
	}
	return (NULL);
}
