NAME = btc

CXX = c++ -g

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp BitcoinExchange.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

BitcoinExchange.o: BitcoinExchange.cpp BitcoinExchange.hpp
	$(CXX) $(CXXFLAGS) -c  BitcoinExchange.cpp -o BitcoinExchange.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all