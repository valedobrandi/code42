NAME = webserv

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC_DIR = src
OBJ_DIR = obj

SRC = main.cpp
OBJ = obj/main.o

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

obj/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all