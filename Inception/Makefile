DOCKER_COMPOSE = docker compose -f ./srcs/docker-compose.yml

all: build

setup:
	mkdir -p /home/yzhuang/data/wordpress
	mkdir -p /home/yzhuang/data/mariadb


build: setup
	${DOCKER_COMPOSE} build --no-cache
	${DOCKER_COMPOSE} up -d

clean:
	${DOCKER_COMPOSE} down

fclean:
	${DOCKER_COMPOSE} down --rmi all --volumes --remove-orphans
	sudo rm -rf /home/yzhuang/data/wordpress
	sudo rm -rf /home/yzhuang/data/mariadb
	docker system prune -a --volumes -f

re: fclean all

.PHONY: all build clean fclean re setup
