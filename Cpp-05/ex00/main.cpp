#include "Bureaucrat.hpp"

int main()
{
	std::cout << "========== Test 1: Valid Bureaucrat ==========" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 42);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "========== Test 2: Grade Too High (0) ==========" << std::endl;
	try
	{
		Bureaucrat bob("bob", 0);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "========== Test 3: Grade Too Low (151) ==========" << std::endl;
	try
	{
		Bureaucrat bob("bob", 151);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "========== Test 4: Increment Grade ==========" << std::endl;
	try
	{
		Bureaucrat bob("bob", 5);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << "After increment: " << bob << std::endl;
		bob.incrementGrade();
		std::cout << "After increment: " << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "========== Test 5: Decrement Grade ==========" << std::endl;
	try
	{
		Bureaucrat bob("bob", 148);
		std::cout << bob << std::endl;
		bob.decrementGrade();
		std::cout << "After decrement: " << bob << std::endl;
		bob.decrementGrade();
		std::cout << "After decrement: " << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "========== Test 6: Increment at Grade 1 (Exception) ==========" << std::endl;
	try
	{
		Bureaucrat bob("bob", 1);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << "After increment: " << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "========== Test 7: Decrement at Grade 150 (Exception) ==========" << std::endl;
	try
	{
		Bureaucrat bob("bob", 150);
		std::cout << bob << std::endl;
		bob.decrementGrade();
		std::cout << "After decrement: " << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	return 0;
}
