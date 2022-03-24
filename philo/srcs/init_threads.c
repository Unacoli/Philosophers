/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:53:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/24 18:28:58 by nargouse         ###   ########.fr       */
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

static int	init_talk(t_rules *rules, t_philo *philo)
{
	pthread_mutex_t	*talk;
	int				i;
	int				*dead;

	talk = malloc(sizeof(pthread_mutex_t));
	if (!talk)
		return (-1);
	dead = malloc(sizeof(int));
	if (!dead)
		return (-1);
	i = 0;
	*dead = 0;
	while (i < rules->nbr_philo)
	{
		pthread_mutex_init(talk, NULL);
		philo[i].talk = talk;
		philo[i].dead = dead;
		i++;
	}
	return (0);
}

static t_philo	*init_philo(t_rules *rules, t_philo *philo,
		pthread_mutex_t **forks)
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
		philo[i].l_fork = forks[i];
		if (i != rules->nbr_philo - 1)
			philo[i].r_fork = forks[i + 1];
		else
			philo[i].r_fork = forks[0];
		i++;
	}
	if (init_talk(rules, philo) == -1)
		return (NULL);
	return (philo);
}

int	thread_handling(t_rules *rules)
{
	t_philo			*philo;
	pthread_mutex_t	**forks;
	pthread_t		id;

	forks = NULL;
	forks = init_forks(rules, forks);
	if (!forks)
		return (-1);
	philo = NULL;
	philo = init_philo(rules, philo, forks);
	if (!philo)
		return (quit(rules, forks, philo, -1));
	if (pthread_create(&id, NULL, &base_thread, philo))
		return (quit(rules, forks, philo, -1));
	if (pthread_join(id, NULL))
		return (quit(rules, forks, philo, -1));
	return (quit(rules, forks, philo, 0));
}
