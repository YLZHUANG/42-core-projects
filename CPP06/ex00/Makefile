# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 11:04:05 by yzhuang           #+#    #+#              #
#    Updated: 2024/12/09 11:06:01 by yzhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ScalarConverter.cpp main.cpp

NAME = ScalarConverter

HEADER =  ScalarConverter.hpp

OBJS = ${SRCS:.cpp=.o}

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 

%.o : %.cpp ${HEADER} 
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
