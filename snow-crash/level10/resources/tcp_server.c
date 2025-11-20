#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>

#define MAX_CLIENTS 1024
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <IP> <PORT>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int err;

	int server_fd;
	const char *ip = argv[1];
	int port = atoi(argv[2]);

	struct sockaddr_in address;
	socklen_t addrlen = sizeof(address);

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	int opt = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr(ip);
	address.sin_port = htons(port);

	err = bind(server_fd, (struct sockaddr *)&address, sizeof(address));
	if (err < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	printf("Listening on %s:%d\n", ip, port);

	err = listen(server_fd, 5);
	if (err < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	int client_fd[MAX_CLIENTS];
	
	memset(client_fd, -1, sizeof(client_fd));

	int max_fd;
	fd_set  read_fds;
	fd_set  client_fds;

	max_fd = server_fd;
	FD_ZERO(&client_fds);
	FD_SET(server_fd, &client_fds);
	while (1)
	{
		FD_ZERO(&read_fds);
		read_fds = client_fds;

		int activity;

		activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
		if (activity < 0)
		{
			perror("select error");
		}

		if (FD_ISSET(server_fd, &read_fds))
		{
			int new_socket;

			new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
			if (new_socket < 0)
			{
				perror("accept");
				exit(EXIT_FAILURE);
			}

			// printf("New connection: socket fd is %d, IP is %s, PORT is %d\n", \
				new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
			
			FD_SET(new_socket, &client_fds);
			if (new_socket > max_fd)
			{
				max_fd = new_socket;
			}
			for (int i = 0; i < MAX_CLIENTS; i++)
			{
				if (client_fd[i] == -1)
				{
					client_fd[i] = new_socket;
					break;
				}
			}
			continue ;
		}

		for (int i = 0; i < MAX_CLIENTS; i++)
		{
			int fd;

			fd = client_fd[i];
			if (fd == -1)
			{
				continue ;
			}

			if (FD_ISSET(fd, &read_fds))
			{
				ssize_t read_value;
				char buffer[BUFFER_SIZE];

				read_value = read(fd, buffer, BUFFER_SIZE - 1);
				if (read_value == 0)
				{
					getpeername(fd, (struct sockaddr *)&address, &addrlen);
					// printf("Client disconnected: IP %s, PORT %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
					FD_CLR(client_fd[i], &client_fds);
					close(fd);
					client_fd[i] = -1;
					if (max_fd == fd)
					{
						max_fd = server_fd;
						for (int i = 0; i < MAX_CLIENTS; i++)
						{
							if (client_fd[i] != -1 && client_fd[i] > max_fd)
							{
								max_fd = client_fd[i];
							}
						}
					}
				}
				else
				{
					buffer[read_value] = '\0';
					if (strstr(buffer, ".*( )*.") == NULL)
					{
						printf("Received from client %d: %s", fd, buffer);
					}
				}
			}
		}
	}

	return 0;
}
