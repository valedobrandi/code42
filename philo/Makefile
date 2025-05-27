# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 16:17:29 by bde-albu          #+#    #+#              #
#    Updated: 2025/05/26 17:43:48 by bde-albu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror -g
CC = cc

DEPS = philo.h

SRC_DIR = src
OBJ_DIR = obj

SRCS = \
actions.c \
ft_atoi.c \
ft_memset.c \
helpers.c \
initialize_settings.c \
main.c \
philosopher_pthread.c \
set_philosophers.c \
set_simulation.c \
simulation_pthread.c

OBJS = \
actions.o \
ft_atoi.o \
ft_memset.o \
helpers.o \
initialize_settings.o \
main.o \
philosopher_pthread.o \
set_philosophers.o \
set_simulation.o \
simulation_pthread.o

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

$(OBJ_DIR)/actions.o: $(SRC_DIR)/actions.c $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/actions.c -o $(OBJ_DIR)/actions.o

$(OBJ_DIR)/philosopher_pthread.o: $(SRC_DIR)/philosopher_pthread.c $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/philosopher_pthread.c -o $(OBJ_DIR)/philosopher_pthread.o

$(OBJ_DIR)/simulation_pthread.o: $(SRC_DIR)/simulation_pthread.c $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/simulation_pthread.c -o $(OBJ_DIR)/simulation_pthread.o

$(OBJ_DIR)/initialize_settings.o: $(SRC_DIR)/initialize_settings.c $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/initialize_settings.c -o $(OBJ_DIR)/initialize_settings.o

$(OBJ_DIR)/set_philosophers.o: $(SRC_DIR)/set_philosophers.c $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/set_philosophers.c -o $(OBJ_DIR)/set_philosophers.o

$(OBJ_DIR)/set_simulation.o: $(SRC_DIR)/set_simulation.c $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/set_simulation.c -o $(OBJ_DIR)/set_simulation.o

$(OBJ_DIR)/helpers.o: $(SRC_DIR)/helpers.c $(DEPS)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/helpers.c -o $(OBJ_DIR)/helpers.o

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re