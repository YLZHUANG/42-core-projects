# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 16:19:44 by yzhuang           #+#    #+#              #
#    Updated: 2024/01/29 16:19:46 by yzhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = my_replace.cpp main.cpp

SRCS_T = my_replace.cpp test.cpp

NAME = SedIsForLosers

NAME_T = Testeur

OBJS = ${SRCS:.cpp=.o}

OBJS_T = ${SRCS_T:.cpp=.o}

HEADER = my_replace.hpp

HEADER_T = test.hpp

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

%.o : %.cpp 
	${CC} ${CFLAGS} -c $< -o $@
	
${NAME}: ${OBJS} $(HEADER)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${NAME_T}: ${OBJS_T} $(HEADER_T)
	${CC} ${CFLAGS} ${OBJS_T} -o ${NAME_T}

all:	${NAME}

clean:
	rm -f ${OBJS} ${OBJS_T} 

fclean:	clean
	rm -f ${NAME} ${NAME_T} 

re:	fclean all

.PHONY:	all clean fclean re 
