/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:50:22 by mmakarov          #+#    #+#             */
/*   Updated: 2023/03/26 17:50:48 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	new_window(t_fr *fr)
{
	fr->mlx = mlx_init();
	fr->mlx_win = mlx_new_window(fr->mlx, WIN_SIZE_X, WIN_SIZE_Y, "fractol");
}

void	new_image(t_fr *fr)
{
	fr->img = mlx_new_image(fr->mlx, WIN_SIZE_X, WIN_SIZE_Y);
	fr->addr = mlx_get_data_addr(fr->img, &fr->bits_per_pixel,
			&fr->line_length, &fr->endian);
}

void	which_fractal(char **av, t_fr *fr)
{
	if (!ft_strcmp(av[1], "Mandelbrot"))
	{
		mandelbrot(fr);
		fr->fractal = ft_strdup("Mandelbrot"); //
	}
	if (!ft_strcmp(av[1], "Julia"))
	{
		fr->param1_julia = av[2];
		fr->param2_julia = av[3];
		julia(fr);
		fr->fractal = ft_strdup("Julia"); //
	}
	if (!ft_strcmp(av[1], "Buddhabrot"))
	{
		buddhabrot(fr);
		fr->fractal = ft_strdup("Buddhabrot"); //
	}
}

void	hooks(t_fr *fr)
{
	mlx_key_hook(fr->mlx_win, key_hook, fr);
	mlx_hook(fr->mlx_win, ON_DESTROY, 0, close_win, fr);
	mlx_mouse_hook(fr->mlx_win, zoom_unzoom, fr);
}

int	main(int argc, char **argv)
{
	t_fr	*fr;

	fr = malloc(sizeof(t_fr)); //
	if (fr == NULL)
		return (0);
	fr->zoom = 4.0;
	fr->x = 0;
	fr->y = 0;
	if (arg_check(argc, argv))
		errors();
	new_window(fr);
	new_image(fr);
	which_fractal(argv, fr);
	mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, 0, 0);
	hooks(fr);
	mlx_loop(fr->mlx);
	return (0);
}
