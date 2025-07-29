NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Bureaucrat.cpp Form.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp Bureaucrat.hpp Form.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

Bureaucrat.o: Bureaucrat.cpp Bureaucrat.hpp Form.hpp
	$(CXX) $(CXXFLAGS) -c  Bureaucrat.cpp -o Bureaucrat.o

Form.o: Form.cpp Form.hpp Form.hpp
	$(CXX) $(CXXFLAGS) -c  Form.cpp -o Form.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all