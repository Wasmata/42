# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 10:33:31 by wasmaata          #+#    #+#              #
#    Updated: 2024/11/18 13:58:59 by wasmaata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c \
			  ft_put.c \
			  ft_putt.c

OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
CC			= gcc -Wall -Wextra -Werror

%.o: %.c ft_printf.h
			${CC} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ft_printf.h
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
