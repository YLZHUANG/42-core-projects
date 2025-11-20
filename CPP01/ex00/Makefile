# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 13:10:32 by yzhuang           #+#    #+#              #
#    Updated: 2024/01/29 13:10:46 by yzhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Zombie.cpp main.cpp

NAME = zombie

OBJS = ${SRCS:.cpp=.o}

HEADER = Zombie.hpp

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

%.o : %.cpp $(HEADER)
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
