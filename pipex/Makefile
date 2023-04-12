SRCS	= main.c\
		  error_checker.c\
		  parsing.c\
		  complicated_split.c\

OBJS	= ${SRCS:.c=.o}

NAME	= pipex

CC		= gcc

RM		= rm -f

HEADERS		= pipex.h

INC_LIBFT	= libft

DEPS		= ${INC_LIBFT}/libft.h

CFLAGS		= -Wall -Wextra -Werror -I. -g3 -fsanitize=address

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADERS}
			${MAKE} -C ${INC_LIBFT}
			${CC} ${CFLAGS} -L ${INC_LIBFT} -lft -o ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}
			${RM}
			${MAKE} -C ${INC_LIBFT} clean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
