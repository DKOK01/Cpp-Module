#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "========== Test 1: Create Valid Form ==========" << std::endl;
	try
	{
		Form taxForm("Tax Form", 50, 25);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}



	std::cout << std::endl;
	std::cout << "========== Test 2: Form Grade Too High (0) ==========" << std::endl;
	try
	{
		Form invalidForm("Invalid", 0, 50);
		std::cout << invalidForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}



	std::cout << std::endl;
	std::cout << "========== Test 3: Form Grade Too Low (151) ==========" << std::endl;
	try
	{
		Form invalidForm("Invalid", 50, 151);
		std::cout << invalidForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}



	std::cout << std::endl;
	std::cout << "========== Test 4: Bureaucrat Signs Form (Success) ==========" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 40);
		Form contract("Contract", 50, 25);
		std::cout << bob << std::endl;
		std::cout << contract << std::endl;
		bob.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}



	std::cout << std::endl;
	std::cout << "========== Test 5: Bureaucrat Signs Form (Failure - Grade Too Low) ==========" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 100);
		Form topSecret("Top Secret", 10, 5);
		std::cout << intern << std::endl;
		std::cout << topSecret << std::endl;
		intern.signForm(topSecret);
		std::cout << topSecret << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}



	std::cout << std::endl;
	return 0;
}
