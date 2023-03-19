/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:33:02 by mmakarov          #+#    #+#             */
/*   Updated: 2023/03/19 20:05:57 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(void)
{
	exit(1);
	return (0);
}

int	arg_check(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "Mandelbrot"))
			return (0);
		if (!ft_strcmp(argv[1], "Buddhabrot"))
			return (0);
	}
	if (argc == 4)
	{
		if (!ft_strcmp(argv[1], "Julia")) // check 3d and 4th params
			return (0);
	}
	return (1);
}

int	errors(void)
{
	write(1, "Error! Valid params:\n", 21);
	write(1, "-->Mandelbrot\n", 14);
	write(1, "-->Julia\n", 9);
	exit(1);
	return (0);
}
