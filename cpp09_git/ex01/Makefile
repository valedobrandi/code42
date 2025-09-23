NAME = RPN

CXX = c++ -g

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp RPN.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp RPN.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

RPN.o: RPN.cpp RPN.hpp
	$(CXX) $(CXXFLAGS) -c  RPN.cpp -o RPN.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all