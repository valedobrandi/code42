NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp Fixed.hpp Point.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

Fixed.o: Fixed.cpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c  Fixed.cpp -o Fixed.o

Point.o: Point.cpp Point.hpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c  Point.cpp -o Point.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all