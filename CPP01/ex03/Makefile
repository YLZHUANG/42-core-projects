# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 13:56:10 by yzhuang           #+#    #+#              #
#    Updated: 2024/01/29 13:59:41 by yzhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp  

NAME = UnnecessaryViolence

OBJS = ${SRCS:.cpp=.o}

HEADER = HumanA.hpp HumanB.hpp Weapon.hpp

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
