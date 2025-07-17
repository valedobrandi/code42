NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp DiamondTrap.hpp ClapTrap.hpp FragTrap.hpp ScavTrap.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

ClapTrap.o: ClapTrap.cpp ClapTrap.hpp
	$(CXX) $(CXXFLAGS) -c  ClapTrap.cpp -o ClapTrap.o

FragTrap.o: FragTrap.cpp FragTrap.hpp ClapTrap.hpp
	$(CXX) $(CXXFLAGS) -c  FragTrap.cpp -o FragTrap.o

ScavTrap.o: ScavTrap.cpp ScavTrap.hpp ClapTrap.hpp
	$(CXX) $(CXXFLAGS) -c  ScavTrap.cpp -o ScavTrap.o

DiamondTrap.o: DiamondTrap.cpp DiamondTrap.hpp ClapTrap.hpp FragTrap.hpp ScavTrap.hpp
	$(CXX) $(CXXFLAGS) -c  DiamondTrap.cpp -o DiamondTrap.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all