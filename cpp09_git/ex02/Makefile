NAME = PmergeMe

CXX = c++ -g

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp PmergeMe.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

PmergeMe.o: PmergeMe.cpp PmergeMe.hpp
	$(CXX) $(CXXFLAGS) -c  PmergeMe.cpp -o PmergeMe.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all