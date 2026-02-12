#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T const &elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void increment(T &elem)
{
	elem++;
}

void toUpper(std::string &s)
{
	for (size_t i = 0; i < s.length(); i++)
		s[i] = static_cast<char>(std::toupper(s[i]));
}

int main(void)
{
	std::cout << "=== Int array ===" << std::endl;
	int intArr[] = {1, 2, 3, 4, 5};
	::iter(intArr, 5, printElement<int>);

	std::cout << "\n=== After increment ===" << std::endl;
	::iter(intArr, 5, increment<int>);
	::iter(intArr, 5, printElement<int>);

	std::cout << "\n=== String array ===" << std::endl;
	std::string strArr[] = {"hello", "world", "foo", "bar"};
	::iter(strArr, 4, printElement<std::string>);

	std::cout << "\n=== After toUpper ===" << std::endl;
	::iter(strArr, 4, toUpper);
	::iter(strArr, 4, printElement<std::string>);

	std::cout << "\n=== Const int array ===" << std::endl;
	int const constArr[] = {10, 20, 30};
	::iter(constArr, 3, printElement<int const>);

	std::cout << "\n=== Double array ===" << std::endl;
	double dblArr[] = {1.1, 2.2, 3.3};
	::iter(dblArr, 3, printElement<double>);

	std::cout << "\n=== Char array ===" << std::endl;
	char charArr[] = {'a', 'b', 'c', 'd'};
	::iter(charArr, 4, printElement<char>);

	return 0;
}
