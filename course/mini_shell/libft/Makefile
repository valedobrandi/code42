# **************************************************************************** #
#                                                                          #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 14:10:20 by bde-albu          #+#    #+#              #
#    Updated: 2025/04/04 12:19:52 by bde-albu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRC = ft_atoi.c ft_isalpha.c  ft_itoa.c ft_memmove.c ft_putnbr_fd.c  ft_strchr.c ft_strlcat.c  ft_strncmp.c  ft_substr.c	\
ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c	\
ft_calloc.c ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_striteri.c ft_strlen.c  ft_strrchr.c ft_toupper.c \
ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strcat.c ft_strjoin.c  ft_strmapi.c ft_strtrim.c

OBJ = ft_atoi.o ft_isalpha.o ft_itoa.o ft_memmove.o ft_putnbr_fd.o ft_strchr.o ft_strlcat.o ft_strncmp.o ft_substr.o	\
ft_bzero.o ft_isascii.o ft_memchr.o ft_memset.o ft_putstr_fd.o ft_strdup.o ft_strlcpy.o ft_strnstr.o ft_tolower.o	\
ft_calloc.o  ft_isdigit.o ft_memcmp.o ft_putchar_fd.o ft_split.o ft_striteri.o ft_strlen.o  ft_strrchr.o ft_toupper.o \
ft_isalnum.o ft_isprint.o ft_memcpy.o ft_putendl_fd.o ft_strcat.o ft_strjoin.o  ft_strmapi.o ft_strtrim.o

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DR)/ft_atoi.o: $(SRC_DR)/ft_atoi.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_atoi.c -o $(OBJ_DR)/ft_atoi.o

$(OBJ_DR)/ft_isalpha.o: $(SRC_DR)/ft_isalpha.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_isalpha.c -o $(OBJ_DR)/ft_isalpha.o

$(OBJ_DR)/ft_itoa.o: $(SRC_DR)/ft_itoa.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_itoa.c -o $(OBJ_DR)/ft_itoa.o

$(OBJ_DR)/ft_memmove.o: $(SRC_DR)/ft_memmove.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_memmove.c -o $(OBJ_DR)/ft_memmove.o

$(OBJ_DR)/ft_putnbr_fd.o: $(SRC_DR)/ft_putnbr_fd.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_putnbr_fd.c -o $(OBJ_DR)/ft_putnbr_fd.o

$(OBJ_DR)/ft_strchr.o: $(SRC_DR)/ft_strchr.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_strchr.c -o $(OBJ_DR)/ft_strchr.o

$(OBJ_DR)/ft_strlcat.o: $(SRC_DR)/ft_strlcat.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_strlcat.c -o $(OBJ_DR)/ft_strlcat.o

$(OBJ_DR)/ft_strncmp.o: $(SRC_DR)/ft_strncmp.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_strncmp.c -o $(OBJ_DR)/ft_strncmp.o

$(OBJ_DR)/ft_substr.o: $(SRC_DR)/ft_substr.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_substr.c -o $(OBJ_DR)/ft_substr.o

$(OBJ_DR)/ft_bzero.o: $(SRC_DR)/ft_bzero.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_bzero.c -o $(OBJ_DR)/ft_bzero.o

$(OBJ_DR)/ft_isascii.o: $(SRC_DR)/ft_isascii.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_isascii.c -o $(OBJ_DR)/ft_isascii.o

$(OBJ_DR)/ft_memchr.o: $(SRC_DR)/ft_memchr.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_memchr.c -o $(OBJ_DR)/ft_memchr.o

$(OBJ_DR)/ft_memset.o: $(SRC_DR)/ft_memset.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_memset.c -o $(OBJ_DR)/ft_memset.o

$(OBJ_DR)/ft_putstr_fd.o: $(SRC_DR)/ft_putstr_fd.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_putstr_fd.c -o $(OBJ_DR)/ft_putstr_fd.o

$(OBJ_DR)/ft_strdup.o: $(SRC_DR)/ft_strdup.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_strdup.c -o $(OBJ_DR)/ft_strdup.o

$(OBJ_DR)/ft_strlcpy.o: $(SRC_DR)/ft_strlcpy.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_strlcpy.c -o $(OBJ_DR)/ft_strlcpy.o

$(OBJ_DR)/ft_strnstr.o: $(SRC_DR)/ft_strnstr.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_strnstr.c -o $(OBJ_DR)/ft_strnstr.o

$(OBJ_DR)/ft_tolower.o: $(SRC_DR)/ft_tolower.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_tolower.c -o $(OBJ_DR)/ft_tolower.o

$(OBJ_DR)/ft_calloc.o: $(SRC_DR)/ft_calloc.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_calloc.c -o $(OBJ_DR)/ft_calloc.o

$(OBJ_DR)/ft_isdigit.o: $(SRC_DR)/ft_isdigit.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_isdigit.c -o $(OBJ_DR)/ft_isdigit.o

$(OBJ_DR)/ft_memcmp.o: $(SRC_DR)/ft_memcmp.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_memcmp.c -o $(OBJ_DR)/ft_memcmp.o

$(OBJ_DR)/ft_putchar_fd.o: $(SRC_DR)/ft_putchar_fd.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_putchar_fd.c -o $(OBJ_DR)/ft_putchar_fd.o

$(OBJ_DR)/ft_split.o: $(SRC_DR)/ft_split.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_split.c -o $(OBJ_DR)/ft_split.o

$(OBJ_DR)/ft_striteri.o: $(SRC_DR)/ft_striteri.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_striteri.c -o $(OBJ_DR)/ft_striteri.o

$(OBJ_DR)/ft_strlen.o: $(SRC_DR)/ft_strlen.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_strlen.c -o $(OBJ_DR)/ft_strlen.o

$(OBJ_DR)/ft_strrchr.o: $(SRC_DR)/ft_strrchr.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_strrchr.c -o $(OBJ_DR)/ft_strrchr.o

$(OBJ_DR)/ft_toupper.o: $(SRC_DR)/ft_toupper.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_toupper.c -o $(OBJ_DR)/ft_toupper.o

$(OBJ_DR)/ft_isalnum.o: $(SRC_DR)/ft_isalnum.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_isalnum.c -o $(OBJ_DR)/ft_isalnum.o

$(OBJ_DR)/ft_isprint.o: $(SRC_DR)/ft_isprint.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_isprint.c -o $(OBJ_DR)/ft_isprint.o

$(OBJ_DR)/ft_memcpy.o: $(SRC_DR)/ft_memcpy.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_memcpy.c -o $(OBJ_DR)/ft_memcpy.o

$(OBJ_DR)/ft_putendl_fd.o: $(SRC_DR)/ft_putendl_fd.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_putendl_fd.c -o $(OBJ_DR)/ft_putendl_fd.o

$(OBJ_DR)/ft_strcat.o: $(SRC_DR)/ft_strcat.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_strcat.c -o $(OBJ_DR)/ft_strcat.o

$(OBJ_DR)/ft_strjoin.o: $(SRC_DR)/ft_strjoin.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_strjoin.c -o $(OBJ_DR)/ft_strjoin.o

$(OBJ_DR)/ft_strmapi.o: $(SRC_DR)/ft_strmapi.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_strmapi.c -o $(OBJ_DR)/ft_strmapi.o

$(OBJ_DR)/ft_strtrim.o: $(SRC_DR)/ft_strtrim.c
	$(CC) $(CFLAGS) -c $(SRC_DR)/ft_strtrim.c -o $(OBJ_DR)/ft_strtrim.o


all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean 
	$(MAKE) all
	