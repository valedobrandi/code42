NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = \
main.cpp \
zombieHorde.cpp \
Zombie.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

zombieHorde.o: zombieHorde.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c zombieHorde.cpp -o zombieHorde.o

Zombie.o: Zombie.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c Zombie.cpp -o Zombie.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all