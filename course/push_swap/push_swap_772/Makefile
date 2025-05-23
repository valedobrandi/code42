NAME = main

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

SRC = main.c push_swap.c utils.c \
push.c rotate_bottom.c rotate_top.c swap.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
