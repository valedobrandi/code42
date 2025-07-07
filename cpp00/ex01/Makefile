NAME = book_contact

CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = \
main.cpp \
contact_class/Contact.class.cpp \
phone_book_class/PhoneBook.class.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp contact_class/Contact.class.hpp phone_book_class/PhoneBook.class.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

contact_class/Contact.class.o: contact_class/Contact.class.cpp contact_class/Contact.class.hpp
	$(CXX) $(CXXFLAGS) -c contact_class/Contact.class.cpp -o contact_class/Contact.class.o

phone_book_class/PhoneBook.class.o: phone_book_class/PhoneBook.class.cpp phone_book_class/PhoneBook.class.hpp contact_class/Contact.class.hpp
	$(CXX) $(CXXFLAGS) -c phone_book_class/PhoneBook.class.cpp -o phone_book_class/PhoneBook.class.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all