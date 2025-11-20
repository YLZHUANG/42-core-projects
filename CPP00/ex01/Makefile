# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 21:09:12 by yzhuang           #+#    #+#              #
#    Updated: 2024/01/29 12:28:22 by yzhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Contact.cpp PhoneBook.cpp main.cpp 

NAME = phonebook

HEADER = PhoneBook.hpp Contact.hpp 

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


