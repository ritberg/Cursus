SRCS_FILES	= fractol.c\
	  my_mlx_pixel_put.c\
	  my_mlx_pixel_put_2.c\
	  mandelbrot.c\
	  julia.c\
	  buddhabrot.c\
	  hooks.c\
	  errors.c\
	  temp_libft.c\
	  ft_atod_isdigit.c\

SRCS_DIR		= src/

# prefix pour lier le dossier et les fichiers dedans
SRCS		= ${addprefix ${SRCS_DIR},${SRCS_FILES}}

OBJS_FILES	= ${SRCS_FILES:.c=.o}

OBJS_DIR	= bin/

OBJS		= ${addprefix ${OBJS_DIR},${OBJS_FILES}}

INCL_FILE	= fractol.h

INCL_DIR	= incl/

INCL		= ${addprefix ${INCL_DIR},${INCL_FILE}}

# ici mlx est le dossier
MLX_DIR		= mlx/

# ici mlx est le nom de la librairie
# -L${MLX_DIR} est le dossier
MLX			= -L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit

NAME	= fractol

CC		= gcc

RM		= rm -f

# -I c'est tjs pour les includes
CFLAGS		= -Wall -Wextra -Werror -I${INCL_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${INCL}
	@mkdir -p ${OBJS_DIR}    #creer le dossier bin avec les .o
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${MAKE} -C ${MLX_DIR}       #compile mlx in the subfolder
			${CC} ${CFLAGS} ${OBJS} ${MLX} -o ${NAME}

all:		${NAME}

bonus:		all

clean:		
		${RM} -r ${OBJS_DIR} #-r pour enlever les repositories dans les reposit.(bin)
		${MAKE} -C ${MLX_DIR} clean

fclean:		clean
		${RM} ${NAME}
		${MAKE} -C ${MLX_DIR} fclean

re:		fclean all


.PHONY: all clean fclean re
