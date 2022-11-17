SRCS	= ft_printf.c\
		  ft_c.c\
		  ft_n.c\
		  ft_str.c\
		  ft_dec_to_hexadec_maj.c\
		  ft_dec_to_hexadec_min.c\
		  ft_dec_to_hexadec_p.c\
		  ft_hex_maj.c\
		  ft_hex_min.c\
		  ft_pointer.c\

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

RM		= rm -f

HEADERS		= ft_printf.h

INC_LIBFT	= ./libft/

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
			${MAKE} -C ${INC_LIBFT} clean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
