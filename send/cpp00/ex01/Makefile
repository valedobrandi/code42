NAME = book_contact

CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = \
main.cpp \
Contact.class.cpp \
PhoneBook.class.cpp \
trim.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp Contact.class.hpp PhoneBook.class.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

trim.o: trim.cpp
	$(CXX) $(CXXFLAGS) -c  trim.cpp -o trim.o

Contact.class.o: Contact.class.cpp Contact.class.hpp
	$(CXX) $(CXXFLAGS) -c Contact.class.cpp -o Contact.class.o

PhoneBook.class.o: PhoneBook.class.cpp PhoneBook.class.hpp Contact.class.hpp
	$(CXX) $(CXXFLAGS) -c PhoneBook.class.cpp -o PhoneBook.class.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all