#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << YELLOW << "FragTrap " << _name << " default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << YELLOW << "FragTrap " << _name << " parameterized constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << YELLOW << "FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << YELLOW << "FragTrap copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << YELLOW << "FragTrap " << _name << " destructor called" << RESET << std::endl;
}



void FragTrap::highFivesGuys(void) {
	std::cout << BOLD << CYAN << "FragTrap " << _name << " requests a positive high five! ✋" << RESET << std::endl;
}
