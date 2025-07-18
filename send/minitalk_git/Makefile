# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 16:36:05 by bde-albu          #+#    #+#              #
#    Updated: 2025/05/20 08:46:09 by bde-albu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

CC = cc
DEPS = minitalk.h
BIN1 = server
SRC1 = server.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ1 = server.o ft_putendl_fd.o ft_putnbr_fd.o

BIN2 = client
SRC2 = client.c ft_atoi.c ft_putendl_fd.c
OBJ2 = client.o ft_atoi.o ft_putendl_fd.o


all: $(BIN1) $(BIN2)

$(BIN1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(BIN1) $(OBJ1)

$(BIN2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(BIN2) $(OBJ2)

server.o: server.c $(DEPS)
	$(CC) $(CFLAGS) -c server.c -o server.o

ft_putendl_fd.o: ft_putendl_fd.c $(DEPS)
	$(CC) $(CFLAGS) -c ft_putendl_fd.c -o ft_putendl_fd.o

ft_putnbr_fd.o: ft_putnbr_fd.c $(DEPS)
	$(CC) $(CFLAGS) -c ft_putnbr_fd.c -o ft_putnbr_fd.o

client.o: client.c $(DEPS)
	$(CC) $(CFLAGS) -c client.c -o client.o

ft_atoi.o: ft_atoi.c $(DEPS)
	$(CC) $(CFLAGS) -c ft_atoi.c -o ft_atoi.o

clean:
	rm -f $(OBJ1) $(OBJ2)

fclean: clean
	rm -f $(BIN1) $(BIN2)

re: fclean all

.PHONY: all clean fclean re
