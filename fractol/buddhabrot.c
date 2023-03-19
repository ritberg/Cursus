/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:36:08 by mmakarov          #+#    #+#             */
/*   Updated: 2023/03/19 19:04:27 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterat_b(t_fr *fr, double *temp)
{
	ft_bzero(temp, 2 * MAX_ITER);
	fr->c_re = (fr->i - WIN_SIZE_X / 2.0) * fr->zoom / WIN_SIZE_X + fr->x;
	fr->c_im = (fr->j - WIN_SIZE_Y / 2.0) * fr->zoom / WIN_SIZE_Y + fr->y;
	while (fr->re * fr->re + fr->im * fr->im < 4 && fr->n < MAX_ITER)
	{
		fr->temp = fr->re * fr->re - fr->im * fr->im + fr->c_re;
		fr->im = 2 * fr->re * fr->im + fr->c_im;
		fr->re = fr->temp;
		temp[fr->n * 2] = fr->re; // les nbr pairs sont les re
		temp[fr->n * 2 + 1] = fr->im; //les nbr impairs sont les im
		fr->n++;
	}
}

void	buddhabrot(t_fr *fr)
{
	double	*temp;
	int	coord_x;
	int	coord_y;

	temp = malloc(sizeof(int) * 2 * MAX_ITER); //stocker les nbr dans un tableau
	if (!temp)
		return ;
	fr->i = 0;
	while (fr->i < WIN_SIZE_X)
	{
		fr->j = 0;
		while (fr->j < WIN_SIZE_Y)
		{
			fr->n = 0;
			fr->re = 0;
			fr->im = 0;
			iterat_b(fr, temp);
			if (fr->n < MAX_ITER)
			{
				while (--(fr->n) >= 0) // decrement., n diminue de 1
				{
					// cf. "c_re" et "c_im" ci-dessus mais avec i et j inconnus
					coord_x = (WIN_SIZE_X / 2) + WIN_SIZE_X / fr->zoom * \
					   	(temp[fr->n * 2] - fr->x);
					coord_y = (WIN_SIZE_Y / 2) + WIN_SIZE_Y / fr->zoom * \
					   	(temp[fr->n * 2 + 1] - fr->y);
					if (coord_x < WIN_SIZE_X && coord_y < WIN_SIZE_Y && \
							coord_x >= 0 && coord_y >= 0) 
						my_mlx_pixel_put_2(fr, coord_x, coord_y, 0x00020202);
				}
			}
			fr->j++;
		}
		fr->i++;
	}
}
