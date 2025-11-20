# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 10:18:26 by yzhuang           #+#    #+#              #
#    Updated: 2024/11/20 10:25:55 by yzhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Bureaucrat.cpp Form.cpp main.cpp

NAME = Form

HEADER = Bureaucrat.hpp Form.hpp

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
