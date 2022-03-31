/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:33:14 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/24 20:47:15 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <limits.h>

typedef struct	s_rules
{
	int	nbr_philo;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	eat_count;
	long long init_time;
}				t_rules;


typedef struct	s_philo
{
	t_rules *rules;
	pthread_t	thread_id;
	int	id;
	int	nbr_eat;
	int	*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*talk;
	pthread_mutex_t	*eat;
	pthread_mutex_t	*m_dead;
	pthread_mutex_t	*time;
	long long last_eat;
}				t_philo;

int	ft_atoi(const char *str);
int	my_wait(int time, t_philo *philo);
long long	get_time(void);
int	error(const char *str);
int	philo_talk(t_philo *philo, char *message, int id);

int	parsing(int ac, char **av, t_rules *rules);

int	thread_handling(t_rules *rules);
void	*base_thread(void *phil);
void	*life(void *phil);

int	all_eat(t_philo *philo);
int	one_dead(t_philo *philo);
int	is_dead(t_philo *philo);
int	dead(t_philo *philo);
long long	mutex_time(t_philo *philo);

int	unlock_forks(t_philo *philo);
int	quit(t_rules *rules, pthread_mutex_t **forks, t_philo *philo, int ret);

#endif
