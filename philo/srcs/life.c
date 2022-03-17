/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:45:44 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/17 18:39:24 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	philo_talk(philo, "has taken a fork\n", philo->id);
	pthread_mutex_lock(philo->r_fork);
	philo_talk(philo, "has taken a fork\n", philo->id);
	pthread_mutex_lock(philo->talk);
	philo_talk(philo, "is eating\n", philo->id);
	philo->last_eat = get_time();
	pthread_mutex_unlock(philo->talk);
	my_wait(philo->rules->eat_time, philo);
	(philo->nbr_eat)--;
	unlock_forks(philo);
}

void	*life(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	while (is_dead(philo) != 1)
		eat(philo);
	return (NULL);
}
