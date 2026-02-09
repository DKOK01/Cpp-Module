#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"



Base* generate(void) {
	int r = std::rand() % 3;
	if (r == 0)
		return new A();
	else if (r == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}
	
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}
	
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}
	
	std::cout << "Unknown" << std::endl;
}

int main() {
	std::srand(std::time(NULL));

	std::cout << "=== Testing generate() and identify() ===" << std::endl;
	
	for (int i = 0; i < 5; i++) {
		std::cout << "\nTest " << i + 1 << ":" << std::endl;
		Base* ptr = generate();
		
		std::cout << "  identify(ptr):  ";
		identify(ptr);
		
		std::cout << "  identify(*ptr): ";
		identify(*ptr);
		
		delete ptr;
	}

	std::cout << "\n=== Manual Tests ===" << std::endl;

	A a;
	B b;
	C c;
	
	std::cout << "A object - pointer:   ";
	identify(&a);
	std::cout << "A object - reference: ";
	identify(a);
	
	std::cout << "B object - pointer:   ";
	identify(&b);
	std::cout << "B object - reference: ";
	identify(b);
	
	std::cout << "C object - pointer:   ";
	identify(&c);
	std::cout << "C object - reference: ";
	identify(c);

	return 0;
}
