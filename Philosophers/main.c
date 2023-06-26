/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:52:22 by mmakarov          #+#    #+#             */
/*   Updated: 2023/06/26 18:39:21 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_ok(int argc, char **argv)
{
	int	arg;
	int	j;

	j = 1;
	while (j < argc)
	{
		if (!is_digit(argv[j]))
			return (error_message(NOT_DIGIT));
		arg = ft_atoi(argv[j]);
		if (j == 1 && (arg <= 0 || arg > 200))
			return (error_message(N_PHILOS));
		if (j != 1 && arg == BIGGER_THAN_INTMAX)
			return (error_message(BIGGER_THAN_INTMAX));
		j++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc - 1 < 4 || argc - 1 > 5)
		return (error_message(ARGS_NUMBER));
	if (!args_ok(argc, argv))
		return (1);
	data = init_data_structure(argc, argv);
	if (!data)
		return (1);
	free_structures(data);
	return (0);
}
