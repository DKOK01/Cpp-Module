#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern
{
public:
	// Orthodox Canonical Form
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	// Member function
	AForm*	makeForm(const std::string& formName, const std::string& target);

private:
	// Helper function type for form creation
	AForm*	createShrubbery(const std::string& target);
	AForm*	createRobotomy(const std::string& target);
	AForm*	createPresidential(const std::string& target);
};

#endif
