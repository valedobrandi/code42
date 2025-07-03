NAME = test_rgb

SRC = \
src/test_rgb.c \
../src/parse/validate_rgb.c \
../src/helpers/is_space.c


INC = -Iinclude -I../include -I../libft
LIB = -L../libft -lft
CRITERION = -lcriterion

$(NAME): $(SRC)
	$(CC) -Wall -Wextra -Werror $(INC) $(SRC) $(LIB) $(CRITERION) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean $(NAME)
