NAME = main

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

SRC = main.c push_swap.c utils.c print_command.c \
push.c rotate_bottom.c rotate_top.c swap.c

OBJ = main.o push_swap.o utils.o print_command.o \
push.o rotate_bottom.o rotate_top.o swap.o

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
