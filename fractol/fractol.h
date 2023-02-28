#ifndef FRACTOL_H
# define FRACTOL_H

# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"

# define WIN_SIZE_X 1920
# define WIN_SIZE_Y 1080
# define MAX_ITER 100

// ???
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17
# define ESC 53
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define UP_KEY 126
# define DOWN_KEY 125

typedef	struct s_fr
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	double	zoom;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;

	double	x;
	double	y;
	double	re;
	double	im;
	double	temp;
	double	c_re;
	double	c_im;
	char	*fractal;
	int	i;
	int	j;
	int	n;

}	t_fr;

//initialisation
void	my_mlx_pixel_put(t_fr *fr, int x, int y, int color);
void	new_window(t_fr *fr);
void	new_image(t_fr *fr);

//errors
int	close_win(void);

//fractals
void	mandelbrot(t_fr *fr);
int	itertion(t_fr *fr);
void	which_fractal(char *str, t_fr *fr);

//hooks
int	key_hook(int key_code, t_fr *fr);
int	mouse_hook(int click);
int	zoom_unzoom(int key_code, t_fr *fr);

//libft
int	ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);

#endif
