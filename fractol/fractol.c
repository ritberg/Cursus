#include "mlx.h"
#include "stdio.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*
void	circle(int r, void *img)
{
    // Consider a rectangle of size N*N
    int N = 2*r+1;
 
    int x, y;  // Coordinates inside the rectangle
 
    // Draw a square of size N*N.
	int	i = 0;
	int	j = 0;
	while (i < N)
	{
		i++;
        while (j < N)
        {
            // Start from the left most corner point
            x = i-r;
            y = j-r;
 
            // If this point is inside the circle, print it
            if (x*x + y*y <= r*r+1 )
				my_mlx_pixel_put(img, x, y, 0x00FF0000);
            else // If outside the circle, print space
                printf(" ");
            printf(" ");
			j++;
        }
        printf("\n");
    }
}
*/

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//	my_mlx_pixel_put(&img, 10, 5, 0x00FF0000);
//	my_mlx_pixel_put(&img, 5, 0, 0x00FF0000);
//	my_mlx_pixel_put(&img, 10, 0, 0x00FF0000);

//	circle(10, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
