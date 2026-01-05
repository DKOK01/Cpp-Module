#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap () : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " default constructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

// Attack function
void ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " cannot attack because it has no hit points left!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " cannot attack because it has no energy points left!" << std::endl;
		return;
	}

	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target 
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
		return;
	}
	
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount 
				  << " points of damage and is destroyed!" << std::endl;
	} else {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount 
				  << " points of damage! (" << _hitPoints << " HP remaining)" << std::endl;
	}
}

// Be repaired function
void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " cannot be repaired because it is destroyed!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " cannot be repaired because it has no energy points left!" << std::endl;
		return;
	}
	
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
			  << " hit points! (" << _hitPoints << " HP total)" << std::endl;
}
