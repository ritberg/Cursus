SRCS	= fractol_2.c\
	  my_mlx_pixel_put.c\
	  my_mlx_pixel_put_2.c\
	  mandelbrot.c\
	  julia.c\
	  buddhabrot.c\
	  hooks.c\
	  errors.c\
	  temp_libft.c\
	  ft_atoi_atod.c\

OBJS	= ${SRCS:.c=.o}

NAME	= fractol

MLX		= mlx

CC		= gcc

RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror -Imlx

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${MAKE} -C ${MLX}       #compile mlx in the subfolder
			mv ${MLX}/libmlx.dylib . #move libmlx to the current folder
			${CC} ${CFLAGS} ${OBJS} -L. -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all:		${NAME}

clean:		
		${RM} ${OBJS}
		${MAKE} -C ${MLX} clean

fclean:		clean
		${RM} ${NAME}
		${RM} libmlx.dylib

re:		fclean all


.PHONY: all clean fclean re test
