# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 11:32:46 by bde-albu          #+#    #+#              #
#    Updated: 2025/04/07 17:07:46 by bde-albu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEPENDENCY_LIBFT = ../libft/libft.a
NAME = libft_printf.a
CFLAGS = -Wall -Wextra -Werror -g
CC = cc

SRC = ft_printf.c ft_putnbr_base.c ft_putptr_hexa.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(DEPENDENCY_LIBFT)
	ar rcs $(NAME) $(OBJ) $(DEPENDENCY_LIBFT)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^

$(DEPENDENCY_LIBFT):
	cd ../libft && $(MAKE) -f Makefile

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all
