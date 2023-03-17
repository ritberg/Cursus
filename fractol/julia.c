/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:35:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/03/17 18:50:06 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterat_j(t_fr *fr)
{
	fr->c_re = -0.8;
	fr->c_im = -0.2;
	while (fr->re * fr->re + fr->im * fr-> im < 4 && fr->n < MAX_ITER)
	{
		/*
		fr->temp = fr->re * fr->re - fr->im * fr->im;
		fr->im = 2 * fr->re * fr->im + fr->c_re;
		fr->re = fr->temp + fr->c_im;
		*/
		fr->temp = fr->re * fr->re - fr->im * fr->im + fr->c_re;
		fr->im = 2 * fr->re * fr->im + fr->c_im;
		fr->re = fr->temp;
		fr->n++;
	}
	return (fr->n);
}

void	julia(t_fr *fr)
{
	fr->i = 0;
	while (fr->i < WIN_SIZE_X)
	{
		fr->j = 0;
		while (fr->j < WIN_SIZE_Y)
		{
			fr->n = 0;
			fr->re = (fr->i - WIN_SIZE_X / 2.0) * fr->zoom / WIN_SIZE_X + fr->x;
			fr->im = (fr->j - WIN_SIZE_Y / 2.0) * fr->zoom / WIN_SIZE_Y + fr->y;
			if (fr->n < MAX_ITER)
				my_mlx_pixel_put(fr, fr->i, fr->j, iterat_j(fr) * 0x0087CEFA);
			fr->j++;
		}
		fr->i++;
	}
}
