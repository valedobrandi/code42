# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 11:32:46 by bde-albu          #+#    #+#              #
#    Updated: 2025/06/23 08:52:02 by bde-albu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = ft_printf.c \
ft_putnbr_base.c \
ft_putptr_hexa.c \
ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \
init_format.c \
print_c.c \
print_s.c \
print_p.c \
print_i_d.c \
print_u_x_upperx.c \
parse_width.c \
parse_flag.c \
parse_precision.c \
parse_type.c \
parse_printf.c \
print_justify_rigth.c \
print_justify_left.c \
print_padding.c \
print_precision.c \
print_space.c \
print_sign.c \
manage_print.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

ft_printf.o: ft_printf.c
	$(CC) $(CFLAGS) -c ft_printf.c -o ft_printf.o

ft_putnbr_base.o: ft_putnbr_base.c
	$(CC) $(CFLAGS) -c ft_putnbr_base.c -o ft_putnbr_base.o

ft_putptr_hexa.o: ft_putptr_hexa.c
	$(CC) $(CFLAGS) -c ft_putptr_hexa.c -o ft_putptr_hexa.o

ft_putchar.o: ft_putchar.c
	$(CC) $(CFLAGS) -c ft_putchar.c -o ft_putchar.o

ft_putstr.o: ft_putstr.c
	$(CC) $(CFLAGS) -c ft_putstr.c -o ft_putstr.o

ft_putnbr.o: ft_putnbr.c
	$(CC) $(CFLAGS) -c ft_putnbr.c -o ft_putnbr.o

init_format.o: init_format.c
	$(CC) $(CFLAGS) -c init_format.c -o init_format.o

print_c.o: print_c.c
	$(CC) $(CFLAGS) -c print_c.c -o print_c.o

print_s.o: print_s.c
	$(CC) $(CFLAGS) -c print_s.c -o print_s.o

print_p.o: print_p.c
	$(CC) $(CFLAGS) -c print_p.c -o print_p.o

print_i_d.o: print_i_d.c
	$(CC) $(CFLAGS) -c print_i_d.c -o print_i_d.o

print_u_x_upperx.o: print_u_x_upperx.c
	$(CC) $(CFLAGS) -c print_u_x_upperx.c -o print_u_x_upperx.o

parse_width.o: parse_width.c
	$(CC) $(CFLAGS) -c parse_width.c -o parse_width.o

parse_flag.o: parse_flag.c
	$(CC) $(CFLAGS) -c parse_flag.c -o parse_flag.o

parse_precision.o: parse_precision.c
	$(CC) $(CFLAGS) -c parse_precision.c -o parse_precision.o

parse_type.o: parse_type.c
	$(CC) $(CFLAGS) -c parse_type.c -o parse_type.o

parse_printf.o: parse_printf.c
	$(CC) $(CFLAGS) -c parse_printf.c -o parse_printf.o

print_justify_rigth.o: print_justify_rigth.c
	$(CC) $(CFLAGS) -c print_justify_rigth.c -o print_justify_rigth.o

print_justify_left.o: print_justify_left.c
	$(CC) $(CFLAGS) -c print_justify_left.c -o print_justify_left.o

print_padding.o: print_padding.c
	$(CC) $(CFLAGS) -c print_padding.c -o print_padding.o

print_precision.o: print_precision.c
	$(CC) $(CFLAGS) -c print_precision.c -o print_precision.o

print_space.o: print_space.c
	$(CC) $(CFLAGS) -c print_space.c -o print_space.o

print_sign.o: print_sign.c
	$(CC) $(CFLAGS) -c print_sign.c -o print_sign.o

manage_print.o: manage_print.c
	$(CC) $(CFLAGS) -c manage_print.c -o manage_print.o

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

all: $(NAME)

bonus: $(NAME)
