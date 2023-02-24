#include "mlx.h"
#include "stdio.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*
int	my_key_funct(int keycode, void *mlx)
{
	printf("key event %d\n", keycode);
	return (0);
}
*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	mandelbrot(int x, int y, void *img)
{
	int	max_iter = 50;
	int	c_r = x;
	int	c_i = y;
	int	z_r = 0;
	int	z_i = 0;
	int	i = 0;
	int	tmp;
	while (z_r*z_r + z_i*z_i < 4 && i <= max_iter)
	{
		tmp = z_r;
		z_r = z_r*z_r - z_i*z_i + c_r;
		z_i = 2*z_i*tmp + c_i;
		i++;
	}
	if (z_r*z_r + z_i*z_i < 4)
		my_mlx_pixel_put(img, x+i, y+i, 0x0066CDAA);

}

void	square(int a, void *img)
{
	int	x, y;
	
	int	i = 960;
	int	j = 540;
	y = -a;
	while (y <= a)
	{
		x = -a;
		while (x <= a)
		{
			if (x <= a / 2 && y <= a / 2)
				my_mlx_pixel_put(img, i+x, j-y, 0x0066CDAA);
			else
				my_mlx_pixel_put(img, i+x, j-y, 0x0000FF7F);
			x++;
		}
		y++;
	}
}


void	circle(int r, void *img)
{
    int x, y;  // Coordinates inside the rectangle
 
	int	i = 960; //center of the circle
	int	j = 540;
    y = -r; //start from the left, bottom (-10, -10 standard plane)
	while (y <= r)
	{
		x = -r;
		while (x <= r) // stop at radius. woth while loops are like a square
        {
			// If this point is inside the circle, print it
            if (x*x + y*y <= r*r + 1) //why + 1
	    		my_mlx_pixel_put(img, i+x, j-y, 0x00FF0000); //center + radius
										// j-y car axe y dans mlx est a l'envers
			x++;
		}
		y++;
    }
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "fractol");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//	my_mlx_pixel_put(&img, 10, 5, 0x00FF0000);
//	my_mlx_pixel_put(&img, 5, 0, 0x00FF0000);
//	my_mlx_pixel_put(&img, 10, 0, 0x00FF0000);

//	move the center
//	my_mlx_pixel_put(&img, 960, 540, 0x00FF0000);

//	circle(10, &img);
	square(10, &img);
//	mandelbrot(960, 540, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, my_key_funct, 0);
	mlx_loop(mlx);
}
