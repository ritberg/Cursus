/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:52:22 by mmakarov          #+#    #+#             */
/*   Updated: 2023/06/24 19:16:16 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(int flag)
{
	printf("Error: invalid arguments\n");
	if (flag == ARGS_NUMBER)
		printf("You should put 4 or 5 digital arguments\n");
	if (flag == NOT_DIGIT)
		printf("You should put only (positive) digits\n");
	if (flag == N_PHILOS)
		printf("Number of philosophers should be 1 <= n <= 200\n");
	if (flag == BIGGER_THAN_INTMAX)
		printf("A digit bigger than 2147483647 is detected\n");
	return (0);
}

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
	if (argc - 1 < 4 || argc - 1 > 5)
		return (error_message(ARGS_NUMBER));
	if (!args_ok(argc, argv))
		return (1);
	return (0);
}
