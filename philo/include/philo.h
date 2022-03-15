/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:33:14 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/15 16:53:14 by nargouse         ###   ########.fr       */
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

typedef struct	s_philo
{
	int	id;
	int	r_fork;
	struct s_rules *rules;
	pthread_t	thread_id;
}				t_philo;

typedef struct	s_rules
{
	t_philo	*philosophers;
	int	nbr_philo;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	eat_count;
}				t_rules;

int	ft_atoi(const char *str);
int	error(const char *str);
int	parsing(int ac, char **av, t_rules *rules);
int	thread_handling(t_rules *rules);

#endif
