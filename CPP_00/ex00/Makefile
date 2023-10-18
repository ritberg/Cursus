BLUE			:= $(shell tput setaf 4)
PASTEL_MAGENTA	:= $(shell tput setaf 213)
RESET			:= $(shell tput sgr0)

SRCS	= megaphone.cpp\
			  main.cpp\

OBJS	= ${SRCS:.c=.o}

INCL	= megaphone.hpp

NAME	= megaphone

CC		= g++

RM		= rm -f

CFLAGS		+= -Wall -Wextra -Werror -std=c++98


.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS} ${INCL}
	@		${CC} ${CFLAGS} -o ${NAME} ${OBJS}
	@echo	"${BLUE} Compilation ${NAME} done ${RESET}"

all:		${NAME}

clean:
		@${RM} ${OBJS}
		@echo "${BLUE} Clean object files done ${RESET}"

fclean:		clean
		@${RM} ${NAME}
		@echo "${BLUE} Clean ${NAME} done ${RESET}"

re:		fclean all


.PHONY: all clean fclean re
