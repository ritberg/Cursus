/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:33:02 by mmakarov          #+#    #+#             */
/*   Updated: 2023/03/26 14:50:01 by mmakarov         ###   ########.fr       */
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
	else if (argc == 4)
	{
		if (!ft_strcmp(argv[1], "Julia"))
			return (0);
		if (!ft_isdigit(argv[2]) || !ft_isdigit(argv[3]))
			return (0);
		if (ft_atoi(argv[2]) > INT_MAX || ft_atoi(argv[2]) < INT_MIN || \
				ft_atoi(argv[3]) > INT_MAX || ft_atoi(argv[3]) < INT_MIN)
			return (0);
		if (ft_atod(argv[2]) > DBL_MAX || ft_atod(argv[2]) < DBL_MIN || \
				ft_atod(argv[3]) > DBL_MAX || ft_atod(argv[3]) < DBL_MIN)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	errors(void)
{
	write(1, "Error! Example of valid params:\n", 32);
	write(1, "-->Mandelbrot\n", 14);
	write(1, "-->Buddhabrot\n", 14);
	write(1, "-->Julia -0.2 -0.8\n", 19);
	exit(1);
	return (0);
}
