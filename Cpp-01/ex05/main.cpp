#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl harl;

	std::cout << "=== Testing Harl's complaints ===" << std::endl << std::endl;

	harl.complain("DEBUG");
	std::cout << std::endl;

	harl.complain("INFO");
	std::cout << std::endl;

	harl.complain("WARNING");
	std::cout << std::endl;

	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "=== Testing invalid level ===" << std::endl;
	harl.complain("INVALID");
	std::cout << std::endl;

	return 0;
}
