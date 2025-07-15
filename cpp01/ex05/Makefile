NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Harl.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp Harl.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

Harl.o: Harl.cpp Harl.hpp
	$(CXX) $(CXXFLAGS) -c  Harl.cpp -o Harl.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all