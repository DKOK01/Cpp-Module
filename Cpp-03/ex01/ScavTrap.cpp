#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN << "ScavTrap " << _name << " default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN << "ScavTrap " << _name << " parameterized constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << GREEN << "ScavTrap copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << GREEN << "ScavTrap copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << GREEN << "ScavTrap " << _name << " destructor called" << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << RED << "ScavTrap " << _name << " cannot attack because it has no hit points left!" << RESET << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << YELLOW << "ScavTrap " << _name << " cannot attack because it has no energy points left!" << RESET << std::endl;
		return;
	}

	_energyPoints--;
	std::cout << CYAN << "ScavTrap " << _name << " fiercely attacks " << target 
			  << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << BOLD << MAGENTA << "ScavTrap " << _name << " is now in Gate keeper mode!" << RESET << std::endl;
}
