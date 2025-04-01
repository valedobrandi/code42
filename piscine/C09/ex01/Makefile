NAME=libft.a
CFILES=srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OFILES=$(CFILES:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

srcs/ft_putchar.o: srcs/ft_putchar.c includes/ft.h
	$(CC) $(CFLAGS) -Iincludes -c srcs/ft_putchar.c -o srcs/ft_putchar.o

srcs/ft_swap.o: srcs/ft_swap.c includes/ft.h
	$(CC) $(CFLAGS) -Iincludes -c srcs/ft_swap.c -o srcs/ft_swap.o

srcs/ft_putstr.o: srcs/ft_putstr.c includes/ft.h
	$(CC) $(CFLAGS) -Iincludes -c srcs/ft_putstr.c -o srcs/ft_putstr.o

srcs/ft_strlen.o: srcs/ft_strlen.c includes/ft.h
	$(CC) $(CFLAGS) -Iincludes -c srcs/ft_strlen.c -o srcs/ft_strlen.o

srcs/ft_strcmp.o: srcs/ft_strcmp.c includes/ft.h
	$(CC) $(CFLAGS) -Iincludes -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
