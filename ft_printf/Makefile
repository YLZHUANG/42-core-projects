# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 18:16:47 by yzhuang           #+#    #+#              #
#    Updated: 2022/12/30 21:25:41 by yzhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_printf.c ft_putn.c ft_strdup.c ft_isdigit.c ft_putptr.c ft_strlen.c ft_printf_a.c ft_putcs.c  ft_putstr_fd.c ft_struct.c ft_printf_b.c ft_putnbr_fd.c ft_putuxx.c
OBJS = ${SRCS:.c=.o}
HEADER = ft_printf.h
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${HEADER}
	ar rc ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

bonus: 	$(OBJS)
	ar rc ${NAME} $(OBJS)

.PHONY:	all clean fclean re