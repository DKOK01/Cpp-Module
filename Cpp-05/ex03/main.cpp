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
	try
	{
		AForm* shrub = intern.makeForm("shrubbery creation", "home");
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
		delete shrub;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Test 2: Create robotomy request form
	std::cout << "\n=== Robotomy Request ===" << std::endl;
	try
	{
		AForm* robot = intern.makeForm("robotomy request", "Bender");
		boss.signForm(*robot);
		boss.executeForm(*robot);
		delete robot;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Test 3: Create presidential pardon form
	std::cout << "\n=== Presidential Pardon ===" << std::endl;
	try
	{
		AForm* pardon = intern.makeForm("presidential pardon", "Arthur");
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
		delete pardon;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Test 4: Invalid form name
	std::cout << "\n=== Invalid Form ===" << std::endl;
	try
	{
		AForm* invalid = intern.makeForm("invalid form", "target");
		delete invalid;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
