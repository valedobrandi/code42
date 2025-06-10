NAME = cub3D

CFLAGS = -g -Ilibs/gnl/include -Iinclude
LDFLAGS = -Llibs/gnl -lgnl

DEPS = include/cub3D.h

SRC = \
src/main.c \
src/parse_map.c

OBJ = \
obj/main.o \
obj/parse_map.o

all: objdir libs $(NAME)

objdir:
	@mkdir -p obj

libs:
	$(MAKE) -C libs/gnl

obj/main.o: src/main.c $(DEPS)
	cc $(CFLAGS) -c src/main.c -o obj/main.o

obj/parse_map.o: src/parse_map.c $(DEPS)
	cc $(CFLAGS) -c src/parse_map.c -o obj/parse_map.o

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME) $(LDFLAGS)
	
re: fclean all

clean:
	rm -f obj/*.o
	$(MAKE) -C libs/gnl clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libs/gnl fclean

.PHONY: all clean fclean re libs objdir


