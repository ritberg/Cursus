#include "fractol.h"

void	my_mlx_pixel_put_2(t_fr *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->line_length + x * (fr->bits_per_pixel / 8));
	*(unsigned int*)dst += color;
}
