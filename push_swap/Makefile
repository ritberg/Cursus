SRCS	= already_sorted.c\
		  big_sort.c\
		  create_pile.c\
		  err_checker.c\
		  middle_sort.c\
		  rules_r.c\
		  rules_s_p.c\
		  sim_to_libft.c\
		  small_sort.c\
		  small_sort_max_10.c\
		  small_sort_r.c\
		  sort_pile_k.c\
		  very_small_sort.c\
		  very_small_sort_r.c\

MAIN	= main.c

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc

RM		= rm -f

HEADERS		= push_swap.h

INC_LIBFT	= libft

CFLAGS		= -Wall -Wextra -Werror -IINC_LIBFT

DEPS		= ${INC_LIBFT}/libft.h

.c.o:
	${CC} ${CFLAGS} -c -I ${INC_LIBFT} $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADERS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${INC_LIBFT}

all:		${NAME}

clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

test:		all
			${CC} ${CFLAGS} -L. -lftprintf -o test ${MAIN}

.PHONY: all clean fclean re test
