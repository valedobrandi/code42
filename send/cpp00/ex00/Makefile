NAME = megaphone

CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = megaphone.cpp

OBJ = megaphone.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

megaphone.o: megaphone.cpp
	$(CXX) $(CXXFLAGS) -c megaphone.cpp -o megaphone.o 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all