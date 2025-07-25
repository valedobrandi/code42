NAME = cub3d

CC = gcc
CFLAGS =  -g

SRC_DR = src
OBJ_DR = obj

CUB3D_DEPS = include/cub3d.h
GNL_DEP = src/get_next_line/get_next_line.h

LIBFT_LIB = lib/libft/libft.a
MLX_LIB = lib/minilibx-linux/libmlx.a

LIBS = -Llib/minilibx-linux -lmlx -lXext -lX11 -lm -lz

INCLUDES = -Ilib/libft -Ilib/minilibx-linux -Iinclude -Isrc/get_next_line

SRC = \
main.c \
read_file.c \
parse_texture_rgb.c \
extract_map.c \
validate_rgb.c \
is_space.c \
validate_schema.c \
fill_check.c \
get_next_line.c \
get_next_line_utils.c \
free_array.c \
free_entries.c \
free_schema.c \
initializer_mlx_image.c \
mem_stack.c \
allocate_scheme.c \
validate_texture.c \
key_hook.c \
set_hook.c \
move_hook.c \
draw_map.c \
cast_raytrace.c \
add.c

OBJ = $(SRC:.c=.o)


SRC_FILES = $(addprefix $(SRC_DR)/, $(SRC))
OBJ_FILES = $(addprefix $(OBJ_DR)/, $(OBJ))

all: $(OBJ_DR) $(LIBFT_LIB) $(MLX_LIB) $(NAME)

$(OBJ_DR):
	mkdir -p $(OBJ_DR)

$(LIBFT_LIB):
	- $(MAKE) -C lib/libft/

$(MLX_LIB):
	- $(MAKE) -C lib/minilibx-linux/

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_FILES) $(LIBS) $(LIBFT_LIB) -o $(NAME) $(INCLUDES)

#src
$(OBJ_DR)/main.o: $(SRC_DR)/main.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/main.c -o $(OBJ_DR)/main.o

#parse
$(OBJ_DR)/read_file.o: $(SRC_DR)/parse/read_file.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/read_file.c -o $(OBJ_DR)/read_file.o
$(OBJ_DR)/parse_texture_rgb.o: $(SRC_DR)/parse/parse_texture_rgb.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/parse_texture_rgb.c -o $(OBJ_DR)/parse_texture_rgb.o
$(OBJ_DR)/validate_rgb.o: $(SRC_DR)/parse/validate_rgb.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/validate_rgb.c -o $(OBJ_DR)/validate_rgb.o
$(OBJ_DR)/extract_map.o: $(SRC_DR)/parse/extract_map.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/extract_map.c -o $(OBJ_DR)/extract_map.o
$(OBJ_DR)/validate_schema.o: $(SRC_DR)/parse/validate_schema.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/validate_schema.c -o $(OBJ_DR)/validate_schema.o
$(OBJ_DR)/fill_check.o: $(SRC_DR)/parse/fill_check.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/fill_check.c -o $(OBJ_DR)/fill_check.o
$(OBJ_DR)/validate_texture.o: $(SRC_DR)/parse/validate_texture.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/validate_texture.c -o $(OBJ_DR)/validate_texture.o

#get_next_line
$(OBJ_DR)/get_next_line.o: $(SRC_DR)/get_next_line/get_next_line.c $(GNL_DEP)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/get_next_line/get_next_line.c -o $(OBJ_DR)/get_next_line.o
$(OBJ_DR)/get_next_line_utils.o: $(SRC_DR)/get_next_line/get_next_line_utils.c $(GNL_DEP)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/get_next_line/get_next_line_utils.c -o $(OBJ_DR)/get_next_line_utils.o

#helper
$(OBJ_DR)/free_array.o: $(SRC_DR)/helpers/free_array.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helpers/free_array.c -o $(OBJ_DR)/free_array.o
$(OBJ_DR)/free_entries.o: $(SRC_DR)/helpers/free_entries.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helpers/free_entries.c -o $(OBJ_DR)/free_entries.o
$(OBJ_DR)/is_space.o: $(SRC_DR)/helpers/is_space.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helpers/is_space.c -o $(OBJ_DR)/is_space.o
$(OBJ_DR)/free_schema.o: $(SRC_DR)/helpers/free_schema.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helpers/free_schema.c -o $(OBJ_DR)/free_schema.o
$(OBJ_DR)/allocate_scheme.o: $(SRC_DR)/helpers/allocate_scheme.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helpers/allocate_scheme.c -o $(OBJ_DR)/allocate_scheme.o
$(OBJ_DR)/mem_stack.o: $(SRC_DR)/helpers/mem_stack.c $(CUB3D_DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helpers/mem_stack.c -o $(OBJ_DR)/mem_stack.o

#mlx_hook
obj/key_hook.o: src/mlx_hooks/key_hook.c include/cub3d.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/mlx_hooks/key_hook.c -o obj/key_hook.o
obj/move_hook.o: src/mlx_hooks/move_hook.c include/cub3d.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/mlx_hooks/move_hook.c -o obj/move_hook.o
obj/set_hook.o: src/mlx_hooks/set_hook.c include/cub3d.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/mlx_hooks/set_hook.c -o obj/set_hook.o
obj/initializer_mlx_image.o: src/mlx_hooks/initializer_mlx_image.c include/cub3d.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/mlx_hooks/initializer_mlx_image.c -o obj/initializer_mlx_image.o

#draw
obj/draw_map.o: src/draw/draw_map.c include/cub3d.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/draw/draw_map.c -o obj/draw_map.o
obj/cast_raytrace.o: src/draw/cast_raytrace.c include/cub3d.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/draw/cast_raytrace.c -o obj/cast_raytrace.o
obj/add.o: src/draw/add.c include/cub3d.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/draw/add.c -o obj/add.o


clean:
	rm -rf $(OBJ_DR)
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/minilibx-linux clean

re: fclean all

.PHONY: all clean fclean re