SRCS	= main.c\

OBJS	= ${SRCS:.c=.o}

NAME	= libftpipex.a

CC		= gcc

RM		= rm -f

HEADERS		= pipex.h

INC_LIBFT	= libft

CFLAGS		= -Wall -Wextra -Werror -IINC_LIBFT

DEPS		= ${INC_LIBFT}/libft.h

.c.o:
	${CC} ${CFLAGS} -c -I ${INC_LIBFT} $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADERS}
			${MAKE} -C ${INC_LIBFT}
			mv ${INC_LIBFT}/libft.a ${NAME}
			@ar rc ${NAME} ${OBJS}
			@ranlib ${NAME}

all:		${NAME}

clean:		
			${RM} ${OBJS}
			${RM}
			${MAKE} -C ${INC_LIBFT} clean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
