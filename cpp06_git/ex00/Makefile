NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp ScalarConverter.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

ScalarConverter.o: ScalarConverter.cpp ScalarConverter.hpp
	$(CXX) $(CXXFLAGS) -c  ScalarConverter.cpp -o ScalarConverter.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all