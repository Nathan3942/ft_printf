# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 03:12:23 by njeanbou          #+#    #+#              #
#    Updated: 2023/11/15 03:24:52 by njeanbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c ft_putchar.c ft_putexa.c ft_putnbr.c ft_putvoid.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBC		= ar rcs
RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${LIBC} ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY : all clean fclean re
