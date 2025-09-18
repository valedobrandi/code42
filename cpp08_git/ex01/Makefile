NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Span.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp Span.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

Span.o: Span.cpp Span.hpp
	$(CXX) $(CXXFLAGS) -c  Span.cpp -o Span.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all