/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:43:34 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/17 18:12:34 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parsing(int ac, char **av, t_rules *rules)
{
	if (is_num(ac, av) == -1)
		return (-1);
	rules->nbr_philo = ft_atoi(av[1]);
	rules->die_time = ft_atoi(av[2]);
	rules->eat_time = ft_atoi(av[3]);
	rules->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		rules->eat_count = ft_atoi(av[5]);
	else
		rules->eat_count = -1;
	return (0);
}
