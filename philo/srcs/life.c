/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:45:44 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/17 16:29:13 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	return (0);
}

void	*life(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	while (philo->dead != 1)
	{

	}
	return (NULL);
}
