#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
    std::string _name;
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();
    void setName(std::string name) {
        _name = name;
        std::cout << "ScavTrap name set to " << _name << std::endl;
    };

	void attack(const std::string& target);
	void guardGate();
};

#endif
