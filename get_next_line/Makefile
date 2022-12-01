SRCS	= get_next_line.c\
		  get_next_line_utils.c\
		  main.c

MAIN	= main.c

OBJS	= ${SRCS:.c=.o}

NAME	= get_next_line

CC		= gcc

RM		= rm -f

HEADERS		= get_next_line.h

CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=12

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADERS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

test:		all
			${CC} ${CFLAGS} -o test ${MAIN} ${OBJS}

.PHONY: all clean fclean re test
