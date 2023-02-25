#include "fractol.h"


int	iteration(t_fr *fr)
{
	fr->x = 0; //where x and y change?
	fr->y = 0;
	fr->c_re = (fr->i - WIN_SIZE_X / 2.0) * fr->zoom / WIN_SIZE_X + fr->x;
	fr->c_im = (fr->j - WIN_SIZE_Y / 2.0) * fr->zoom / WIN_SIZE_Y + fr->y;
	while (fr->re * fr->re + fr->im * fr->im < 4 && fr->n < MAX_ITER)
	{
		//why temp? calculate im with old re
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
			if (fr->n < MAX_ITER)
				my_mlx_pixel_put(fr, fr->i, fr->j, iteration(fr) * 0x0087CEFA);
			fr->j++;
		}
		fr->i++;
	}
}
