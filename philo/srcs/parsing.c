/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:43:34 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/15 16:56:58 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int ac, char **av, t_rules *rules)
{
	rules->nbr_philo = ft_atoi(av[1]);
	rules->die_time = ft_atoi(av[2]);
	rules->eat_time = ft_atoi(av[3]);
	rules->sleep_time = ft_atoi(av[4]);
	if (!rules->nbr_philo || !rules->die_time || !rules->eat_time
		|| !rules->sleep_time)
		return (-1);
	if (ac > 5)
	{
		rules->eat_count = ft_atoi(av[5]);
		if (!rules->eat_count)
			return (-1);
	}
	else
		rules->eat_count = -1;
	return (0);
}
