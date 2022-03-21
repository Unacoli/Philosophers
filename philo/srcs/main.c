/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:32:18 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/21 02:35:55 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_rules	rules;

	if (ac < 5 || ac > 6)
		return (error("Wrong number of arguments"));
	if (parsing(ac, av, &rules))
		return (error("Parsing error, check value of arguments"));
	if (thread_handling(&rules))
		return (error("Error on thread creation or on runtime."));
	if (ac == 6)
		printf("Philosophers have eaten %d times.\n", rules.eat_count);
	return (EXIT_SUCCESS);
}
