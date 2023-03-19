#ifndef FRACTOL_H
# define FRACTOL_H

# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"

# define WIN_SIZE_X 1920
# define WIN_SIZE_Y 1080
# define MAX_ITER 100

# define DB_MAX 1.7976931348623158e+308

# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define MOUSE_LEFT 1
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
	char	*param1_julia;
	char	*param2_julia;
	char	*fractal;
	int	i;
	int	j;
	int	n;

}	t_fr;

//initialisation
void	my_mlx_pixel_put(t_fr *fr, int x, int y, int color);
void	my_mlx_pixel_put_2(t_fr *fr, int x, int y, int color);
void	new_window(t_fr *fr);
void	new_image(t_fr *fr);

//errors
int	close_win(void);
int	errors(void);
int	arg_check(int argc, char **argv);

//fractals
void	mandelbrot(t_fr *fr);
void	julia(t_fr *fr);
void	buddhabrot(t_fr *fr); //
int	itertat_m(t_fr *fr);
int	iterat_j(t_fr *fr);
void	itertat_b(t_fr *fr, double *temp); //
void	which_fractal(char **av, t_fr *fr);

//hooks
int	key_hook(int key_code, t_fr *fr);
int	mouse_hook(int click);
int	zoom_unzoom(int key_code, int x, int y, t_fr *fr);

//libft
int	ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
void    ft_bzero(void *s, size_t n);
double	ft_atoi(const char *str);

#endif
