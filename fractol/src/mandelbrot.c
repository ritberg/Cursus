/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:36:08 by mmakarov          #+#    #+#             */
/*   Updated: 2023/03/30 12:16:56 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterat_m(t_fr *fr)
{
	//fr->x = 0; //where x and y change? why x, y are needed?
	//fr->y = 0;
	fr->c_re = (fr->i - WIN_SIZE_X / 2.0) * fr->zoom / WIN_SIZE_X + fr->x;
	fr->c_im = (fr->j - WIN_SIZE_Y / 2.0) * fr->zoom / WIN_SIZE_Y + fr->y;
	while (fr->re * fr->re + fr->im * fr->im < 4 && fr->n < MAX_ITER)
	{
		//temp calculates im with old re
		fr->temp = fr->re * fr->re - fr->im * fr->im + fr->c_re;
		fr->im = 2 * fr->re * fr->im + fr->c_im;
		fr->re = fr->temp;
		fr->n++;
	}
	return (fr->n);
}

void	mandelbrot(t_fr *fr)
{
	fr->i = 0;
	while (fr->i < WIN_SIZE_X)
	{
		fr->j = 0;
		while (fr->j < WIN_SIZE_Y)
		{
			fr->n = 0;
			fr->re = 0;
			fr->im = 0;
			fr->couleur = iterat_m(fr) * 0x0087CEFA;
			if (fr->couleur <= 16777215) // 256*256*256 - 1
				my_mlx_pixel_put(fr, fr->i, fr->j, fr->couleur);
			else
				// mettre a 0 le premier octet de la couleur (transparence)
				// garder tout ce qui est apres
			   // ex of &:
			   // 0 & 1   0	
			   // 1 & 0   0
			   // 1 & 1   1	
			// on a donc : 01011001 & 00111111   00011001 (les deux premiers
			// seront tjs 00
				my_mlx_pixel_put(fr, fr->i, fr->j, fr->couleur & 0x00FFFFFF);
			fr->j++;
		}
		fr->i++;
	}
}
