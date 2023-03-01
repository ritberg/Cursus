/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:29:45 by mmakarov          #+#    #+#             */
/*   Updated: 2023/03/01 18:23:58 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	key_hook(int key_code, t_fr *fr)
{
	if (key_code == ESC)
		exit(1);
	if (key_code == LEFT_KEY)
		fr->x += 0.1;
	if (key_code == RIGHT_KEY)
		fr->x -= 0.1;
	if (key_code == UP_KEY)
		fr->y += 0.1;
	if (key_code == DOWN_KEY)
		fr->y -= 0.1;
	mlx_clear_window(fr->mlx, fr->mlx_win);
	if (!ft_strcmp(fr->fractal, "Mandelbrot"))
		mandelbrot(fr);
	mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, fr->x, fr->y);
	//else
	//	printf("%d\n", key_code);
	return (0);
}

int	zoom_unzoom(int key_code, int x, int y, t_fr *fr) //dsnt work
{
	x = 0;
	y = 0;
	while (x < WIN_SIZE_X)
	{
		while (y < WIN_SIZE_Y)
		{
			if (key_code == ON_MOUSEDOWN || key_code == ON_MOUSEUP)
			{
				if (key_code == ON_MOUSEDOWN)
					fr->zoom /= 0.9;
				else
					fr->zoom *= 0.9;
			}
			/*
			mlx_clear_window(fr->mlx, fr->mlx_win); //it should zoom without clearing!
			if (!ft_strcmp(fr->fractal, "Mandelbrot"))
				mandelbrot(fr);
			*/
			mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
/*
int	mouse_hook(int click)
{
	if (click == 1)
		printf("%s\n", "left");
	else if (click == 2)
		printf("%s\n", "right");
	return (0);
}
*/
