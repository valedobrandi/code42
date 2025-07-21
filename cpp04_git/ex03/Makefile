NAME = main

CXX = c++

CXXFLAGS =  -std=c++98

SRC = \
main.cpp \
Ice.cpp \
Cure.cpp \
ICharacter.cpp \
Character.cpp \
AMateria.cpp \
IMateriaSource.cpp \
MateriaSource.cpp

DEPS = \
Ice.hpp \
Cure.hpp \
ICharacter.hpp \
Character.hpp \
AMateria.hpp \
IMateriaSource.hpp \
MateriaSource.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

Ice.o: Ice.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c  Ice.cpp -o Ice.o

Cure.o: Cure.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c  Cure.cpp -o Cure.o

ICharacter.o: ICharacter.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c  ICharacter.cpp -o ICharacter.o

Character.o: Character.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c  Character.cpp -o Character.o

AMateria.o: AMateria.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c  AMateria.cpp -o AMateria.o

IMateriaSource.o: IMateriaSource.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c  IMateriaSource.cpp -o IMateriaSource.o

MateriaSource.o: MateriaSource.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c  MateriaSource.cpp -o MateriaSource.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all