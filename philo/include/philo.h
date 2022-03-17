/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:33:14 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/17 16:28:24 by nargouse         ###   ########.fr       */
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
	struct timeval init_time;
}				t_rules;


typedef struct	s_philo
{
	t_rules *rules;
	pthread_t	thread_id;
	int	id;
	int	nbr_eat;
	int	dead;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	talk;
	struct timeval last_eat;
}				t_philo;

int	ft_atoi(const char *str);
int	error(const char *str);
int	parsing(int ac, char **av, t_rules *rules);
int	thread_handling(t_rules *rules);
void	*life(void *phil);
long long	get_time(void);
void	my_wait(int time, t_philo *philo);
int	is_dead(t_philo *philo);

#endif
