SRCS	= already_sorted.c\
		  big_sort.c\
		  create_pile.c\
		  err_checker.c\
		  ft_split.c\
		  ft_strjoin.c\
		  middle_sort.c\
		  rules_r.c\
		  rules_s_p.c\
		  sim_to_libft.c\
		  small_sort.c\
		  sm_sort_max_10.c\
		  small_sort_r.c\
		  sort_pile_k.c\
		  temp_libft.c\
		  very_small_sort.c\
		  very_small_sort_r.c\
		  main.c\

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc

RM		= rm -f

HEADERS		= push_swap.h

CFLAGS		= -Wall -Wextra -Werror  -g3

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADERS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

#test:		all
#			${CC} ${CFLAGS} -lpush_swap -o test ${MAIN}

.PHONY: all clean fclean re test
