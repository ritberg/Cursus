/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_choose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:55:20 by mmakarov          #+#    #+#             */
/*   Updated: 2023/02/17 13:24:45 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errors(int argc, char **argv)
{
	int	j;

	j = 1;
	if (argc <= 1)
	{
		write(1, "Valid params:\n", 14);
		write(1, "-->Mandelbrot\n", 14);
		write(1, "-->Julia\n", 9);
	}
	while (argv[j] != "Mandelbrot" || argv[j] != "Julia")
	{
		write(1, "Valid params:\n", 14);
		write(1, "-->Mandelbrot\n", 14);
		write(1, "-->Julia\n", 9);
		j++;
	}
}

void	choose_fract(int argc, char **argv)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		if (argv[j] == "Mandelbrot")
			blbla; //
		else if (argv[j] == "Julia")
			blbla; //
		j++;
	}
}
