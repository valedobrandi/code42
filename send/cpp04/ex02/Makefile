NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = \
main.cpp \
Cat.cpp \
Dog.cpp \
Animal.cpp \
WrongAnimal.cpp \
WrongCat.cpp \
Brain.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

Cat.o: Cat.cpp Cat.hpp Animal.hpp Brain.hpp
	$(CXX) $(CXXFLAGS) -c Cat.cpp -o Cat.o

Dog.o: Dog.cpp Dog.hpp Animal.hpp Brain.hpp
	$(CXX) $(CXXFLAGS) -c Dog.cpp -o Dog.o

Animal.o: Animal.cpp Animal.hpp
	$(CXX) $(CXXFLAGS) -c Animal.cpp -o Animal.o

Brain.o: Brain.cpp Brain.hpp
	$(CXX) $(CXXFLAGS) -c Brain.cpp -o Brain.o

WrongAnimal.o: WrongAnimal.cpp
	$(CXX) $(CXXFLAGS) -c WrongAnimal.cpp -o WrongAnimal.o

WrongCat.o: WrongCat.cpp WrongCat.hpp WrongAnimal.hpp
	$(CXX) $(CXXFLAGS) -c WrongCat.cpp -o WrongCat.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all