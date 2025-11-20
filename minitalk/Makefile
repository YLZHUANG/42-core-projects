# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 19:44:07 by yzhuang           #+#    #+#              #
#    Updated: 2023/08/24 14:11:08 by yzhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERVER = server.c common.c main.c

SRC_CLIENT = client.c common.c

SRC_SERVER_B = server_bonus.c common_bonus.c main_bonus.c

SRC_CLIENT_B = client_bonus.c common_bonus.c

SERVER = server

CLIENT = client

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

HEADER = minitalk.h

HEADER_BONUS = minitalk_bonus.h

CC = cc

CFLAGS = -Wall -Werror -Wextra

all:	${SERVER} ${CLIENT}

bonus:	${SERVER_BONUS} ${CLIENT_BONUS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

OBJ_SERVER = ${SRC_SERVER:.c=.o}

OBJ_SERVER_B = ${SRC_SERVER_B:.c=.o}

OBJ_CLIENT = ${SRC_CLIENT:.c=.o}

OBJ_CLIENT_B = ${SRC_CLIENT_B:.c=.o}

$(SERVER):	$(OBJ_SERVER)
			make -C ./ft_printf
			$(CC) $(OBJ_SERVER) -L./ft_printf -lftprintf -o $(SERVER)
			
$(CLIENT):	$(OBJ_CLIENT)
			$(CC) $(OBJ_CLIENT) -L./ft_printf -lftprintf -o $(CLIENT)

${SERVER_BONUS}:	$(OBJ_SERVER_B)
					make -C ./ft_printf
					$(CC) $(OBJ_SERVER_B) -L./ft_printf -lftprintf -o $(SERVER_BONUS)
				
${CLIENT_BONUS}:	$(OBJ_CLIENT_B)
					$(CC) $(OBJ_CLIENT_B) -L./ft_printf -lftprintf -o $(CLIENT_BONUS)				

clean:
	rm -f ${OBJ_SERVER} $(OBJ_SERVER_B) ${OBJ_CLIENT} $(OBJ_CLIENT_B) 
	@$(MAKE) -C ./ft_printf clean

fclean:	clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@$(MAKE) -C ./ft_printf fclean

re:	fclean all

.PHONY:	all clean fclean re bonus
