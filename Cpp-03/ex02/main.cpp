#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	
	std::cout << std::endl << "=== Test 1: FragTrap Construction/Destruction Chaining ===" << std::endl;
	{
		FragTrap frag("Fraggy");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: FragTrap Attack Function ===" << std::endl;
	{
		FragTrap warrior("Destroyer");
		warrior.attack("Enemy1");
		warrior.attack("Enemy2");
		warrior.attack("Enemy3");
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: FragTrap Take Damage ===" << std::endl;
	{
		FragTrap tank("Armored");
		tank.takeDamage(40);
		tank.takeDamage(30);
		tank.takeDamage(35);
		tank.takeDamage(10);
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: FragTrap Repair Function ===" << std::endl;
	{
		FragTrap healer("Medic");
		healer.takeDamage(70);
		healer.beRepaired(40);
		healer.beRepaired(25);
		healer.attack("Target");
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: FragTrap High Five Special Ability ===" << std::endl;
	{
		FragTrap friendly("Buddy");
		friendly.highFivesGuys();
		friendly.attack("Training Dummy");
		friendly.highFivesGuys();
	}
	std::cout << std::endl;

	std::cout << "=== Test 7: ScavTrap vs FragTrap Comparison ===" << std::endl;
	{

		std::cout << "\nCreating ScavTrap:" << std::endl;
		ScavTrap scav("Scavvy");

		std::cout << "\nCreating FragTrap:" << std::endl;
		FragTrap frag("Fraggy");
		
		std::cout << "\nScavTrap attack (20 damage):" << std::endl;
		scav.attack("Target");
		frag.takeDamage(20);
		
		std::cout << "\nFragTrap attack (30 damage):" << std::endl;
		frag.attack("Target");
		scav.takeDamage(30);

		std::cout << "\nScavTrap special ability:" << std::endl;
		scav.guardGate();
		
		std::cout << "\nFragTrap special ability:" << std::endl;
		frag.highFivesGuys();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
