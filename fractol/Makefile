SRCS	= fractol.c\

OBJS	= ${SRCS:.c=.o}

NAME	= fractol

CC		= gcc

RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror -Imlx

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${OBJ} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all:		${NAME}

clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all


.PHONY: all clean fclean re test
