/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:53:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/17 16:24:37 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	**init_forks(t_rules *rules, pthread_mutex_t **forks)
{
	int	i;

	forks = malloc(rules->nbr_philo * sizeof(pthread_mutex_t));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < rules->nbr_philo)
	{
		forks[i] = malloc(sizeof(pthread_mutex_t));
		if (!forks[i])
			return (NULL);
		pthread_mutex_init(forks[i], NULL);
		i++;
	}
	return (forks);
}

static t_philo	*init_philo(t_rules *rules, t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	philo = malloc(rules->nbr_philo * sizeof(t_philo));
	if (!philo)
		return (NULL);
	while (i < rules->nbr_philo)
	{
		philo[i].nbr_eat = 0;
		philo[i].id = i + 1;
		philo[i].rules = rules;
		philo[i].dead = 0;
		philo[i].l_fork = forks[i];
		if (i != rules->nbr_philo - 1)
			philo[i].r_fork = forks[i + 1];
		else
			philo[i].r_fork = forks[0];
		i++;
	}
	free(forks);
	return (philo);
}

int	thread_handling(t_rules *rules)
{
	t_philo			*philo;
	pthread_mutex_t	**forks;
	int				i;

	forks = NULL;
	forks = init_forks(rules, forks);
	if (!forks)
		return (-1);
	philo = NULL;
	philo = init_philo(rules, philo, *forks);
	if (!philo)
		return (-1);
	gettimeofday(&rules->init_time, NULL);
	i = 0;
	while (i < rules->nbr_philo)
	{
		philo[i].last_eat = rules->init_time;
		if (pthread_create(&(philo[i].thread_id), NULL, &life, &(philo[i])))
			return (-1);
		i++;
	}
	return (0);
}
