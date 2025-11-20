# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 20:39:40 by yzhuang           #+#    #+#              #
#    Updated: 2023/06/16 12:43:04 by yzhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = check.c initnclear.c devide.c count.c costs.c operation1.c operation2.c operation3.c sort.c main.c tools_lst.c tools_tab.c tools_str.c finalise.c

SRCS_BONUS = get_next_line.c get_next_line_utils.c checker.c checker_ops.c check.c initnclear.c operation1.c operation2.c operation3.c tools_lst.c tools_tab.c tools_str.c

NAME = push_swap

NAME_BONUS = checker

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

HEADER = push_swap.h

HEADER_BONUS = checker.h get_next_line.h

CC = cc

CFLAGS = -Wall -Werror -Wextra

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} $(HEADER)
	${CC} ${OBJS} -o ${NAME}
	
${NAME_BONUS}: ${OBJS_BONUS} $(HEADER_BONUS)
	${CC} ${OBJS_BONUS} -o ${NAME_BONUS}

all: ${NAME} 

bonus: $(NAME_BONUS)

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME} $(NAME_BONUS)

re: fclean all

.PHONY:	all clean fclean re bonus
