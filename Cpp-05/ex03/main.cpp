#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	Bureaucrat boss("Boss", 1);

	// Test 1: Create shrubbery creation form
	std::cout << "=== Shrubbery Creation ===" << std::endl;
	AForm* shrub = intern.makeForm("shrubbery creation", "home");
	if (shrub)
	{
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
		delete shrub;
	}

	// Test 2: Create robotomy request form
	std::cout << "\n=== Robotomy Request ===" << std::endl;
	AForm* robot = intern.makeForm("robotomy request", "Bender");
	if (robot)
	{
		boss.signForm(*robot);
		boss.executeForm(*robot);
		delete robot;
	}

	// Test 3: Create presidential pardon form
	std::cout << "\n=== Presidential Pardon ===" << std::endl;
	AForm* pardon = intern.makeForm("presidential pardon", "Arthur");
	if (pardon)
	{
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
		delete pardon;
	}

	// Test 4: Invalid form name
	std::cout << "\n=== Invalid Form ===" << std::endl;
	AForm* invalid = intern.makeForm("invalid form", "target");
	if (invalid)
		delete invalid;

	return 0;
}
