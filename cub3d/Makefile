NAME = cub3d

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

SRC_DR = src
OBJ_DR = obj

SRC = \
main.c \
read_file.c \
parse_texture_rgb.c \
extract_map.c \
validate_rgb.c \
is_space.c \
validate_schema.c \
get_next_line.c \
get_next_line_utils.c \
free_array.c \
free_entries.c \
free_schema.c

OBJ = $(SRC:.c=.o)

CUB3D_DEPS = include/cub3d.h
GNL_DEP = src/get_next_line/get_next_line.h

LIBFT_DR = libft
LIBFT_A = $(LIBFT_DR)/libft.a

INCLUDES = -I$(LIBFT_DR) -Iinclude -Isrc/get_next_line

SRC_FILES = $(addprefix $(SRC_DR)/, $(SRC))
OBJ_FILES = $(addprefix $(OBJ_DR)/, $(OBJ))

all: $(OBJ_DR) $(LIBFT_A) $(NAME)

$(OBJ_DR):
	mkdir -p $(OBJ_DR)

$(LIBFT_A):
	- $(MAKE) -C $(LIBFT_DR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_A) -o $(NAME) $(INCLUDES) 
#main
$(OBJ_DR)/main.o: $(SRC_DR)/main.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/main.c -o $(OBJ_DR)/main.o
#parse
$(OBJ_DR)/read_file.o: $(SRC_DR)/parse/read_file.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/read_file.c -o $(OBJ_DR)/read_file.o
$(OBJ_DR)/parse_texture_rgb.o: $(SRC_DR)/parse/parse_texture_rgb.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/parse_texture_rgb.c -o $(OBJ_DR)/parse_texture_rgb.o
$(OBJ_DR)/validate_rgb.o: $(SRC_DR)/parse/validate_rgb.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/validate_rgb.c -o $(OBJ_DR)/validate_rgb.o
$(OBJ_DR)/extract_map.o: $(SRC_DR)/parse/extract_map.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/extract_map.c -o $(OBJ_DR)/extract_map.o
$(OBJ_DR)/validate_schema.o: $(SRC_DR)/parse/validate_schema.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/validate_schema.c -o $(OBJ_DR)/validate_schema.o
#get_next_line
$(OBJ_DR)/get_next_line.o: $(SRC_DR)/get_next_line/get_next_line.c $(GNL_DEP)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/get_next_line/get_next_line.c -o $(OBJ_DR)/get_next_line.o
$(OBJ_DR)/get_next_line_utils.o: $(SRC_DR)/get_next_line/get_next_line_utils.c $(GNL_DEP)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/get_next_line/get_next_line_utils.c -o $(OBJ_DR)/get_next_line_utils.o
#helper
$(OBJ_DR)/free_array.o: $(SRC_DR)/helpers/free_array.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helpers/free_array.c -o $(OBJ_DR)/free_array.o
$(OBJ_DR)/free_entries.o: $(SRC_DR)/helpers/free_entries.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helpers/free_entries.c -o $(OBJ_DR)/free_entries.o
$(OBJ_DR)/is_space.o: $(SRC_DR)/helpers/is_space.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helpers/is_space.c -o $(OBJ_DR)/is_space.o
$(OBJ_DR)/free_schema.o: $(SRC_DR)/helpers/free_schema.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helpers/free_schema.c -o $(OBJ_DR)/free_schema.o
clean:
	rm -rf $(OBJ_DR)
	$(MAKE) -C $(LIBFT_DR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DR) fclean
	
re: fclean all

.PHONY: all clean fclean re