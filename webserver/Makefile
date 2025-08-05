NAME = webserv

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -Iinclude

SRC_DIR = src
OBJ_DIR = obj

SRC = main.cpp Server.cpp
OBJ = obj/main.o obj/Server.o

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

obj/main.o: src/main.cpp include/webserv.hpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o

# SERVER
obj/Server.o: src/server/Server.cpp include/Server.hpp include/webserv.hpp
	$(CXX) $(CXXFLAGS) -c src/server/Server.cpp -o obj/Server.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all