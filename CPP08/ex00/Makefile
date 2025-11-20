

SRCS = main.cpp

NAME = easyfind

HEADER =  easyfind.hpp

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
