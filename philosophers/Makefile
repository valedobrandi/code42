# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 16:17:29 by bde-albu          #+#    #+#              #
#    Updated: 2025/05/23 15:01:31 by bde-albu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

CFLAGS = -Wall -Wextra -Werror -g
CC = cc

DEPS = philo.h

SRC_DIR = src
OBJ_DIR = obj

SRCS = main.c ft_atoi.c ft_memset.c stack.c
OBJS = main.o ft_atoi.o ft_memset.o stack.o

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/ft_atoi.o: $(SRC_DIR)/ft_atoi.c $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ft_atoi.c -o $(OBJ_DIR)/ft_atoi.o

$(OBJ_DIR)/ft_memset.o: $(SRC_DIR)/ft_memset.c $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ft_memset.c -o $(OBJ_DIR)/ft_memset.o

$(OBJ_DIR)/stack.o: $(SRC_DIR)/stack.c $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/stack.c -o $(OBJ_DIR)/stack.o

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re