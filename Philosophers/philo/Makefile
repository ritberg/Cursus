# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 19:42:13 by mmakarov          #+#    #+#              #
#    Updated: 2023/07/02 08:23:00 by mmakarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE			:= $(shell tput setaf 4)
PASTEL_MAGENTA	:= $(shell tput setaf 213)
RESET			:= $(shell tput sgr0)

SRCS_FILES	= main.c\
	  errors_frees.c\
	  structures_init.c\
	  philos_init.c\
	  utils.c\

SRCS_DIR		= srcs/

# prefix pour lier le dossier et les fichiers dedans
SRCS		= ${addprefix ${SRCS_DIR},${SRCS_FILES}}

OBJS_FILES	= ${SRCS_FILES:.c=.o}

OBJS_DIR	= objs/

OBJS		= ${addprefix ${OBJS_DIR},${OBJS_FILES}}

INCL_FILE	= philo.h

INCL_DIR	= incls/

INCL		= ${addprefix ${INCL_DIR},${INCL_FILE}}

NAME	= philo

CC		= gcc

RM		= rm -f

CFLAGS		+= -Wall -Wextra -Werror -pthread

SAN		?= 0

ifeq ($(SAN), 1)
CFLAGS += -g -fsanitize=thread
$(info ${PASTEL_MAGENTA} SANITIZER ON${RESET})
else
$(info ${PASTEL_MAGENTA} SANITIZER OFF${RESET})
endif

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${INCL}
	@mkdir -p ${OBJS_DIR}    #creer le dossier bin avec les .o
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	@		${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo	"${BLUE} Compilation ${NAME} done ${RESET}"

all:		${NAME}

clean:		
		@${RM} -r ${OBJS_DIR} #-r pour enlever les repositories dans les reposit.(bin)
		@echo "${BLUE} Clean object files done ${RESET}"

fclean:		clean
		@${RM} ${NAME}
		@echo "${BLUE} Clean ${NAME} done ${RESET}"

re:		fclean all


.PHONY: all clean fclean re
