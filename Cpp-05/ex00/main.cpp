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
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Test 3: Grade Too Low (151) ==========" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 151);
		std::cout << charlie << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Test 4: Increment Grade ==========" << std::endl;
	try
	{
		Bureaucrat dave("Dave", 5);
		std::cout << dave << std::endl;
		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl;
		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Test 5: Decrement Grade ==========" << std::endl;
	try
	{
		Bureaucrat eve("Eve", 148);
		std::cout << eve << std::endl;
		eve.decrementGrade();
		std::cout << "After decrement: " << eve << std::endl;
		eve.decrementGrade();
		std::cout << "After decrement: " << eve << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Test 6: Increment at Grade 1 (Exception) ==========" << std::endl;
	try
	{
		Bureaucrat frank("Frank", 1);
		std::cout << frank << std::endl;
		frank.incrementGrade();
		std::cout << "After increment: " << frank << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Test 7: Decrement at Grade 150 (Exception) ==========" << std::endl;
	try
	{
		Bureaucrat grace("Grace", 150);
		std::cout << grace << std::endl;
		grace.decrementGrade();
		std::cout << "After decrement: " << grace << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Test 8: Copy Constructor ==========" << std::endl;
	try
	{
		Bureaucrat original("Original", 50);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Test 9: Assignment Operator ==========" << std::endl;
	try
	{
		Bureaucrat a("A", 10);
		Bureaucrat b("B", 100);
		std::cout << "Before assignment:" << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;
		b = a;
		std::cout << "After b = a:" << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Test 10: Edge Cases ==========" << std::endl;
	try
	{
		Bureaucrat lowest("Lowest", 150);
		Bureaucrat highest("Highest", 1);
		std::cout << lowest << std::endl;
		std::cout << highest << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
