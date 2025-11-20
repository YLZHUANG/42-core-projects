# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 18:41:28 by yzhuang           #+#    #+#              #
#    Updated: 2023/11/20 18:41:30 by yzhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = actions.c error.c main_bonus.c sem.c core.c life.c printtime.c support.c

NAME = philo_bonus

OBJS = ${SRCS:.c=.o}

HEADER = philo_bonus.h

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
