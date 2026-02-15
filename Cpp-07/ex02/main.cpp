#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
	std::cout << "=== Default constructor (empty array) ===" << std::endl;
	Array<int> empty;
	std::cout << "Size: " << empty.size() << std::endl;




	std::cout << "\n=== Parameterized constructor ===" << std::endl;
	Array<int> intArr(5);
	std::cout << "Size: " << intArr.size() << std::endl;
	std::cout << "Default values: ";
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;




	std::cout << "\n=== Assigning values ===" << std::endl;
	for (unsigned int i = 0; i < intArr.size(); i++)
		intArr[i] = (i + 1) * 10;
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;




	std::cout << "\n=== Copy constructor (deep copy) ===" << std::endl;
	Array<int> copyArr(intArr);
	std::cout << "Copy: ";
	for (unsigned int i = 0; i < copyArr.size(); i++)
		std::cout << copyArr[i] << " ";
	std::cout << std::endl;

	copyArr[0] = 999;
	std::cout << "After modifying copy[0] = 999:" << std::endl;
	std::cout << "Original[0]: " << intArr[0] << std::endl;
	std::cout << "Copy[0]: " << copyArr[0] << std::endl;




	std::cout << "\n=== Out of bounds exception ===" << std::endl;
	try {
		std::cout << intArr[100] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}




	std::cout << "\n=== Access on empty array ===" << std::endl;
	try {
		std::cout << empty[0] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}




	std::cout << "\n=== String array ===" << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "World";
	strArr[2] = "42";
	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << std::endl;

	return 0;
}
