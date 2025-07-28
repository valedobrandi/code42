#include "Form.hpp"

Form::Form(void) : _name(""), _isSigned(0), _requireSing(0), _requireExecute(0)
{
}

Form::Form(const Form &other)
	:_requireExecute( getRequireExecute() ),
	 _requireSing( getRequireSing() )
{
	this->_isSigned = other.getIsSigned();
	return ;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_isSigned = other.getIsSigned();
	return (*this);
}

Form::~Form(void)
{
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name),
	_isSigned(false), _requireSing(validateGrade(signGrade)),
	_requireExecute(validateGrade(executeGrade))
{
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int Form::getRequireSing() const
{
	return (this->_requireSing);
}

int Form::getRequireExecute() const
{
	return (this->_requireExecute);
}

void Form::beSigned(Bureaucrat &t)
{
	if (t.getGrade() > this->getRequireSing())
		throw GradeTooLowException();
	this->_isSigned = true;
}

int Form::validateGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 0)
		throw GradeToohigthException();
	return (grade);
}

std::ostream &operator<<(std::ostream &out, const Form &value)
{
	out << "name: " << value.getName()
	<< " signed: " << value.getIsSigned()
	<< " require grade to sign: " << value.getRequireSing()
	<< " require grade to execute: " << value.getRequireExecute()
	<< std::endl;
}
