#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	
	std::cout << std::endl << "=== Test 1: ScavTrap Construction/Destruction Chaining ===" << std::endl;
	{
		ScavTrap scav("Guardian");
		std::cout << "(ScavTrap created)" << std::endl;
	}
	std::cout << "(Note: ClapTrap constructor called first, then ScavTrap constructor)" << std::endl;
	std::cout << "(Destruction in reverse order: ScavTrap destructor, then ClapTrap destructor)" << std::endl;
	std::cout << std::endl;

	std::cout << "=== Test 2: ScavTrap Attack Function ===" << std::endl;
	{
		ScavTrap warrior("Warrior");
		warrior.attack("Enemy1");
		warrior.attack("Enemy2");
		warrior.attack("Enemy3");
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: ScavTrap Take Damage ===" << std::endl;
	{
		ScavTrap tank("Tank");
		tank.takeDamage(30);
		tank.takeDamage(50);
		tank.takeDamage(25); // Should be destroyed (100 total)
		tank.takeDamage(10); // Already destroyed
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: ScavTrap Repair Function ===" << std::endl;
	{
		ScavTrap healer("Healer");
		healer.takeDamage(60);
		healer.beRepaired(30);
		healer.beRepaired(20);
		healer.attack("Target");
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: ScavTrap Guard Gate Special Ability ===" << std::endl;
	{
		ScavTrap gatekeeper("Gatekeeper");
		gatekeeper.guardGate();
		gatekeeper.attack("Intruder");
		gatekeeper.guardGate();
	}
	std::cout << std::endl;

	std::cout << "=== Test 6: ScavTrap Energy Depletion ===" << std::endl;
	{
		ScavTrap exhausted("Exhausted");
		for (int i = 0; i < 52; i++) {
			exhausted.attack("Enemy");
		}
	}
	std::cout << std::endl;

	std::cout << "=== Test 7: ClapTrap vs ScavTrap Comparison ===" << std::endl;
	{
		std::cout << "Creating ClapTrap:" << std::endl;
		ClapTrap clap("Clappy");
		std::cout << "\nCreating ScavTrap:" << std::endl;
		ScavTrap scav("Scavvy");
		
		std::cout << "\nClapTrap attack:" << std::endl;
		clap.attack("Target");
		std::cout << "\nScavTrap attack:" << std::endl;
		scav.attack("Target");
		
		std::cout << "\nScavTrap special ability:" << std::endl;
		scav.guardGate();
	}
	std::cout << std::endl;

	return 0;
}
