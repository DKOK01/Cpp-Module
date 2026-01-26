#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "========== Test 1: ShrubberyCreationForm ==========" << std::endl;
	try
	{
		Bureaucrat gardener("Gardener", 130);
		ShrubberyCreationForm shrub("home");
		
		std::cout << gardener << std::endl;
		std::cout << shrub << std::endl;
		
		gardener.signForm(shrub);
		gardener.executeForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}



	std::cout << std::endl;
	std::cout << "========== Test 2: RobotomyRequestForm ==========" << std::endl;
	try
	{
		Bureaucrat scientist("Dr. Frankenstein", 40);
		RobotomyRequestForm robot("Bender");
		
		std::cout << scientist << std::endl;
		std::cout << robot << std::endl;
		
		scientist.signForm(robot);
		scientist.executeForm(robot);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}



	std::cout << std::endl;
	std::cout << "========== Test 3: PresidentialPardonForm ==========" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("killer");
		
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}



	std::cout << std::endl;
	std::cout << "========== Test 4: Execute Without Signing ==========" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("office");
		
		std::cout << boss << std::endl;
		std::cout << shrub << std::endl;
		boss.executeForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Test 5: Grade Too Low to Sign ==========" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm pardon("Criminal");
		
		std::cout << intern << std::endl;
		std::cout << pardon << std::endl;
		
		intern.signForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Test 6: Grade Too Low to Execute ==========" << std::endl;
	try
	{
		Bureaucrat signer("High Signer", 20);
		Bureaucrat executor("Low Executor", 100);
		RobotomyRequestForm robot("Target");
		
		std::cout << signer << std::endl;
		std::cout << executor << std::endl;
		std::cout << robot << std::endl;
		
		signer.signForm(robot);
		executor.executeForm(robot);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}
