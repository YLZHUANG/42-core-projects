# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 14:35:06 by yzhuang           #+#    #+#              #
#    Updated: 2023/11/20 16:50:58 by yzhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = clean.c eat.c genesis.c live.c main.c manage.c question.c rationalism.c single.c

NAME = philo

OBJS = ${SRCS:.c=.o}

HEADER = philo.h

CC = cc

CFLAGS = -Wall -Werror -Wextra

%.o : %.c $(HEADER)
	${CC} ${CFLAGS} -c $< -o $@
	
${NAME}: ${OBJS} 
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
	rm -f ${OBJS} 

fclean:	clean
	rm -f ${NAME} 

re:	fclean all

.PHONY:	all clean fclean re 
