/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:35:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/03/01 16:50:59 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterat_j(t_fr *fr)
{
	fr->x = 0;
	fr->y = 0;
	fr->c_re = (fr->i - WIN_SIZE_X / 2.0) * fr->zoom / WIN_SIZE_X + fr->x;
	fr->c_im = (fr->j - WIN_SIZE_Y / 2.0) * fr->zoom / WIN_SIZE_Y + fr->y;
	while (fr->re * fr->re + fr->im * fr-> im < 4 && fr->n < MAX_ITER)
	{
		fr->temp = fr->re;
		fr->re = fr->re * fr->re - fr->im * fr->im + fr->c_re;
		fr->im = 2 * fr->im * fr->temp + fr->c_im;
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
