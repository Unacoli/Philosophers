/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:32:03 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/17 18:04:32 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_talk(t_philo *philo, char *message, int id)
{
	pthread_mutex_lock(philo->talk);
	if (is_dead(philo) != 1)
	{
		printf("%lli %d %s\n", get_time() - philo->rules->init_time,
			id, message);
	}
	pthread_mutex_unlock(philo->talk);
}
