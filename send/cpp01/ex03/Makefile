NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp Weapon.hpp HumanA.hpp HumanB.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

Weapon.o: Weapon.cpp Weapon.hpp
	$(CXX) $(CXXFLAGS) -c  Weapon.cpp -o Weapon.o

HumanA.o: HumanA.cpp HumanA.hpp Weapon.hpp
	$(CXX) $(CXXFLAGS) -c  HumanA.cpp -o HumanA.o

HumanB.o: HumanB.cpp HumanB.hpp Weapon.hpp
	$(CXX) $(CXXFLAGS) -c  HumanB.cpp -o HumanB.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all