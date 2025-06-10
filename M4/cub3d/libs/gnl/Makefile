SRC = gnl_utils.c gnl.c

OBJ = $(SRC:.c=.o)

all: libgnl.a

gnl.o: gnl.c include/get_next_line.h
	cc -c gnl.c

gnl_utils.o: gnl_utils.c include/get_next_line.h
	cc -c gnl_utils.c

libgnl.a: gnl.o gnl_utils.o
	ar rcs libgnl.a gnl.o gnl_utils.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libgnl.a

.PHONY: all clean fclean