# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 09:25:09 by bde-albu          #+#    #+#              #
#    Updated: 2025/06/02 14:17:25 by bde-albu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror -g3
CC = cc

SRC_DR = src
OBJ_DR = obj

SRC = \
signals.c \
main.c	\
parse_prompt.c	\
quote_error.c	\
print_prompt.c	\
tokenize.c	\
validate_token.c	\
build_pipeline.c	\
builtin_echo.c	\
execute_command.c	\
builtin_pwd.c	\
builtin_cd.c	\
free_array.c

OBJ = \
signals.o \
main.o	\
parse_prompt.o \
quote_error.o	\
print_prompt.o	\
tokenize.o	\
validate_token.o	\
build_pipeline.o	\
builtin_echo.o	\
execute_command.o	\
builtin_pwd.o	\
builtin_cd.o	\
free_array.o

DEPS = include/minishell.h
PARSE_DPES = include/parse_def.h

LIBFT_DR = libft
LIBFT_A = $(LIBFT_DR)/libft.a

INCLUDES = -I$(LIBFT_DR) -Iinclude

LBS = -lreadline -lncurses

SRC_FILES = $(addprefix $(SRC_DR)/, $(SRC))
OBJ_FILES = $(addprefix $(OBJ_DR)/, $(OBJ))

all: $(OBJ_DR) $(LIBFT_A) $(NAME)

$(OBJ_DR):
	mkdir -p $(OBJ_DR)

$(LIBFT_A):
	- $(MAKE) -C $(LIBFT_DR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_A) -o $(NAME) $(LBS) $(INCLUDES)

$(OBJ_DR)/main.o: $(SRC_DR)/main.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/main.c -o $(OBJ_DR)/main.o

$(OBJ_DR)/signals.o: $(SRC_DR)/signals.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/signals.c -o $(OBJ_DR)/signals.o

$(OBJ_DR)/print_prompt.o: $(SRC_DR)/print_prompt.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/print_prompt.c -o $(OBJ_DR)/print_prompt.o

$(OBJ_DR)/parse_prompt.o: $(SRC_DR)/parse/parse_prompt.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/parse_prompt.c -o $(OBJ_DR)/parse_prompt.o

$(OBJ_DR)/quote_error.o: $(SRC_DR)/parse/quote_error.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/quote_error.c -o $(OBJ_DR)/quote_error.o

$(OBJ_DR)/validate_token.o: $(SRC_DR)/parse/validate_token.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/validate_token.c -o $(OBJ_DR)/validate_token.o

$(OBJ_DR)/tokenize.o: $(SRC_DR)/parse/tokenize.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/tokenize.c -o $(OBJ_DR)/tokenize.o

$(OBJ_DR)/build_pipeline.o: $(SRC_DR)/command/build_pipeline.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/command/build_pipeline.c -o $(OBJ_DR)/build_pipeline.o

$(OBJ_DR)/builtin_echo.o: $(SRC_DR)/built_in/builtin_echo.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/built_in/builtin_echo.c -o $(OBJ_DR)/builtin_echo.o

$(OBJ_DR)/builtin_pwd.o: $(SRC_DR)/built_in/builtin_pwd.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/built_in/builtin_pwd.c -o $(OBJ_DR)/builtin_pwd.o

$(OBJ_DR)/builtin_cd.o: $(SRC_DR)/built_in/builtin_cd.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/built_in/builtin_cd.c -o $(OBJ_DR)/builtin_cd.o

$(OBJ_DR)/execute_command.o: $(SRC_DR)/execute/execute_command.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/execute/execute_command.c -o $(OBJ_DR)/execute_command.o

$(OBJ_DR)/free_array.o: $(SRC_DR)/helper/free_array.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helper/free_array.c -o $(OBJ_DR)/free_array.o


clean:
	rm -rf $(OBJ_DR)
	$(MAKE) -C $(LIBFT_DR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DR) fclean

re: fclean all

.PHONY: all clean fclean re
