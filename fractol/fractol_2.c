#include "mlx.h"
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




void	which_fractal(char *str, t_fr *fr)
{
	if (!ft_strcmp(str, "Mandelbrot"))
	{
		mandelbrot(fr);
		fr->fractal = ft_strdup("Mandelbrot");
	}
}




int	main(int argc, char **argv)
{
	t_fr	*fr;

	fr = malloc(sizeof(t_fr));
	fr->zoom = 4.0;
	new_window(fr);
	new_image(fr);
	if (argc != 2)
		return (0);
	which_fractal(argv[1], fr);
	mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, 0, 0);
	mlx_loop(fr->mlx);
	return (0);
}
