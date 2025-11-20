# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 16:47:49 by yzhuang           #+#    #+#              #
#    Updated: 2024/01/29 16:50:58 by yzhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Harl.cpp main.cpp

NAME = harlFilter

OBJS = ${SRCS:.cpp=.o}

HEADER = Harl.hpp

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
