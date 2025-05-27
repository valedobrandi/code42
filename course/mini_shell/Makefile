# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 09:25:09 by bde-albu          #+#    #+#              #
#    Updated: 2025/05/27 13:13:29 by bde-albu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC_DR = src
OBJ_DR = obj

SRC = \
built_in_command.c \
main.c

OBJ = \
built_in_command.o \
main.o

LBS = -lreadline -lncurses

SRC_FILES = $(addprefix $(SRC_DR)/, $(SRC))
OBJ_FILES = $(addprefix $(OBJ_DR)/, $(OBJ))

all: $(OBJ_DR) $(NAME)

$(OBJ_DR):
	mkdir -p $(OBJ_DR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LBS)

$(OBJ_DR)/main.o: $(SRC_DR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/main.c -o $(OBJ_DR)/main.o

$(OBJ_DR)/built_in_command.o: $(SRC_DR)/built_in_command.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/built_in_command.c -o $(OBJ_DR)/built_in_command.o

clean:
	rm -rf $(OBJ_DR)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
