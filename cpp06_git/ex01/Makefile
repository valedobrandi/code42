NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Serializer.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp Serializer.hpp data.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

Serializer.o: Serializer.cpp Serializer.hpp data.hpp
	$(CXX) $(CXXFLAGS) -c  Serializer.cpp -o Serializer.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all