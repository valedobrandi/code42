# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 11:32:46 by bde-albu          #+#    #+#              #
#    Updated: 2025/04/10 11:51:39 by bde-albu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = ft_printf.c ft_putnbr_base.c ft_putptr_hexa.c ft_putchar.c ft_putstr.c ft_putnbr.c init_format.c \
print_c.c print_s.c print_p.c print_i_d.c print_u_x_upperx.c \
parse_width.c parse_flag.c parse_precision.c parse_type.c parse_printf.c \
print_justify_rigth.c print_justify_left.c print_padding.c print_precision.c print_space.c print_sign.c \
manage_print.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

all: $(NAME)

bonus: $(NAME)
