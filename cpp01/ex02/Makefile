NAME = main

CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all