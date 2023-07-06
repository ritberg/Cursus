/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:52:22 by mmakarov          #+#    #+#             */
/*   Updated: 2023/07/06 15:16:04 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

/*
   We can have only digits
   Number of philos can be from 1 to 200
   All other args should be smaller than INT_MAX
*/
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

/*
   1. Check the right number of arguments (4 or 5 max)
   2. Check args values (in the function args_ok() above
   3. Initialize data structures (two of them, cf. philo.h)
   4. Initialize philosophers threads and a checker thread
   5. Join them separately
   6. Destroy mutexes and free malloced data structures
*/
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
	if (!init_threads_philos_checker(data))
		return (1);
	if (!join_threads_philos_checker(data))
		return (1);
	mutex_destroy(data);
	free_structures(data);
	return (0);
}
