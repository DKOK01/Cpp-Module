#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Orthodox Canonical Form
Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}



// Private helper functions
AForm* Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}



// Main member function
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	// Array of form names
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// Array of member function pointers
	AForm* (Intern::*formCreators[3])(const std::string&) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	// Search and create
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			AForm* form = (this->*formCreators[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}

	// Form not found
	throw FormNotFoundException();
}

// Exception
const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form type not found!";
}
