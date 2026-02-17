#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << "===== Test with std::vector =====" << std::endl;
	{
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 3);

		std::cout << "Vector: ";
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		try
		{
			std::vector<int>::iterator it = easyfind(vec, 9);
			std::cout << "Found value: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::vector<int>::iterator it = easyfind(vec, 42);
			std::cout << "Found value: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "===== Test with std::list =====" << std::endl;
	{
		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(7);
		lst.push_back(42);
		lst.push_back(100);
		lst.push_back(-5);

		std::cout << "List: ";
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		try
		{
			std::list<int>::iterator it = easyfind(lst, 42);
			std::cout << "Found value: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::list<int>::iterator it = easyfind(lst, 0);
			std::cout << "Found value: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "===== Test with std::deque =====" << std::endl;
	{
		std::deque<int> deq;
		deq.push_back(10);
		deq.push_back(20);
		deq.push_back(30);
		deq.push_back(40);
		deq.push_back(50);

		std::cout << "Deque: ";
		for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		try
		{
			std::deque<int>::iterator it = easyfind(deq, 30);
			std::cout << "Found value: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::deque<int>::iterator it = easyfind(deq, 99);
			std::cout << "Found value: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
