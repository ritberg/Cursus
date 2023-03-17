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
		fr->fractal = ft_strdup("Mandelbrot"); //
	}
	if (!ft_strcmp(str, "Julia"))
	{
		julia(fr);
		fr->fractal = ft_strdup("Julia"); //
	}
}


void	hooks(t_fr *fr)
{
	mlx_key_hook(fr->mlx_win, key_hook, fr);
	mlx_hook(fr->mlx_win, ON_DESTROY, 0, close, fr);
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
	new_window(fr);
	new_image(fr);
	if (argc != 2 || arg_problem(argv))
		errors();
	which_fractal(argv[1], fr);
	mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, 0, 0);
	hooks(fr);
	mlx_loop(fr->mlx);
	return (0);
}
