/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_frees.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:36:24 by mmakarov          #+#    #+#             */
/*   Updated: 2023/06/26 19:40:32 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

void	free_structures(t_data *data)
{
	int	i;

	if (data->philosophers)
	{
		i = 0;
		while (i < data->n_philos)
		{
			if (data->philosophers[i])
				free(data->philosophers[i]);
			i++;
		}
		free(data->philosophers);
	}
	free(data);
}

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
