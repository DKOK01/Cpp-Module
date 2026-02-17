#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "===== Subject test =====" << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}



	std::cout << std::endl;
	std::cout << "===== Test: Span full exception =====" << std::endl;
	{
		Span sp = Span(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);

		try
		{
			sp.addNumber(4);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}




	std::cout << std::endl;
	std::cout << "===== Test: No span (empty / one element) =====" << std::endl;
	{
		Span sp = Span(5);

		try
		{
			sp.shortestSpan();
		}
		catch (std::exception& e)
		{
			std::cout << "Empty: " << e.what() << std::endl;
		}

		sp.addNumber(42);

		try
		{
			sp.longestSpan();
		}
		catch (std::exception& e)
		{
			std::cout << "One element: " << e.what() << std::endl;
		}
	}




	std::cout << std::endl;
	std::cout << "===== Test: 10,000 numbers =====" << std::endl;
	{
		Span sp = Span(10000);

		std::srand(std::time(NULL));
		for (int i = 0; i < 10000; i++)
			sp.addNumber(std::rand());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	}




	std::cout << std::endl;
	std::cout << "===== Test: addRange with iterators =====" << std::endl;
	{
		Span sp = Span(10);

		std::vector<int> vec;
		for (int i = 0; i < 5; i++)
			vec.push_back(i * 10);

		sp.addRange(vec.begin(), vec.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	}




	std::cout << std::endl;
	std::cout << "===== Test: addRange overflow =====" << std::endl;
	{
		Span sp = Span(3);
		sp.addNumber(1);

		std::vector<int> vec;
		for (int i = 0; i < 5; i++)
			vec.push_back(i);

		try
		{
			sp.addRange(vec.begin(), vec.end());
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "===== Test: Copy constructor =====" << std::endl;
	{
		Span sp1 = Span(5);
		sp1.addNumber(1);
		sp1.addNumber(100);

		Span sp2(sp1);
		std::cout << "Original - Longest span: " << sp1.longestSpan() << std::endl;
		std::cout << "Copy     - Longest span: " << sp2.longestSpan() << std::endl;
	}

	return 0;
}
