/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:43:34 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/16 17:49:20 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int ac, char **av, t_rules *rules)
{
	rules->nbr_philo = ft_atoi(av[1]);
	rules->die_time = ft_atoi(av[2]);
	rules->eat_time = ft_atoi(av[3]);
	rules->sleep_time = ft_atoi(av[4]);
	if (rules->nbr_philo < 0 || rules->die_time < 0 || rules->eat_time < 0
		|| rules->sleep_time < 0)
		return (-1);
	if (ac == 6)
	{
		rules->eat_count = ft_atoi(av[5]);
		if (rules->eat_count < 0)
			return (-1);
	}
	else
		rules->eat_count = -1;
	return (0);
}
