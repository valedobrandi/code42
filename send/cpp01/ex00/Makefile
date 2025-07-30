NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = \
main.cpp \
newZombie.cpp \
Zombie.cpp \
randomChump.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

newZombie.o: newZombie.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c newZombie.cpp -o newZombie.o

Zombie.o: Zombie.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c Zombie.cpp -o Zombie.o

randomChump.o: randomChump.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c randomChump.cpp -o randomChump.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all