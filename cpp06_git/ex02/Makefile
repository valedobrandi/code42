NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp A.cpp B.cpp C.cpp Base.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp Base.hpp A.hpp B.hpp C.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

Base.o: Base.cpp Base.hpp 
	$(CXX) $(CXXFLAGS) -c  Base.cpp -o Base.o

A.o: A.cpp A.hpp 
	$(CXX) $(CXXFLAGS) -c  A.cpp -o A.o

B.o: B.cpp B.hpp
	$(CXX) $(CXXFLAGS) -c  B.cpp -o B.o

C.o: C.cpp C.hpp
	$(CXX) $(CXXFLAGS) -c  C.cpp -o C.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all