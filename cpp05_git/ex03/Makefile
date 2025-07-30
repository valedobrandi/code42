NAME = main

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp \
Bureaucrat.cpp \
AForm.cpp \
ShrubberyCreationForm.cpp \
RobotomyRequestForm.cpp \
PresidentialPardonForm.cpp \
Intern.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp Bureaucrat.hpp AForm.hpp
	$(CXX) $(CXXFLAGS) -c  main.cpp -o main.o

Bureaucrat.o: Bureaucrat.cpp Bureaucrat.hpp AForm.hpp
	$(CXX) $(CXXFLAGS) -c  Bureaucrat.cpp -o Bureaucrat.o

AForm.o: AForm.cpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c  AForm.cpp -o AForm.o

ShrubberyCreationForm.o: ShrubberyCreationForm.cpp AForm.hpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c  ShrubberyCreationForm.cpp -o ShrubberyCreationForm.o

RobotomyRequestForm.o: RobotomyRequestForm.cpp AForm.hpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c  RobotomyRequestForm.cpp -o RobotomyRequestForm.o

PresidentialPardonForm.o: PresidentialPardonForm.cpp AForm.hpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c  PresidentialPardonForm.cpp -o PresidentialPardonForm.o

Intern.o: Intern.cpp AForm.hpp Intern.hpp
	$(CXX) $(CXXFLAGS) -c  Intern.cpp -o Intern.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all