#include "ClapTrap.hpp"

int main() {
	
	std::cout << std::endl << "=== Test 1: Attack Function ===" << std::endl;
	{
		ClapTrap Attacker("Attacker");
		Attacker.attack("Target1");
		Attacker.attack("Target2");
		Attacker.attack("Target3");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: Take Damage ===" << std::endl;
	{
		ClapTrap Tank("Tank");
		Tank.takeDamage(3);
		Tank.takeDamage(5);
		Tank.takeDamage(10); // Should be destroyed
		Tank.takeDamage(5);  // Already destroyed
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: Repair Function ===" << std::endl;
	{
		ClapTrap Healer("Healer");
		Healer.takeDamage(5);
		Healer.beRepaired(3);
		Healer.beRepaired(2);
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Energy Depletion (Attack) ===" << std::endl;
	{
		ClapTrap Exhausted("Exhausted");
		for (int i = 0; i < 12; i++) {
			Exhausted.attack("Enemy");
		}
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: Energy Depletion (Repair) ===" << std::endl;
	{
		ClapTrap Tired("Tired");
		Tired.takeDamage(9);
		for (int i = 0; i < 11; i++) {
			Tired.beRepaired(1);
		}
	}
	std::cout << std::endl;

	std::cout << "=== Test 6: Dead ClapTrap Cannot Act ===" << std::endl;
	{
		ClapTrap Zombie("Zombie");
		Zombie.takeDamage(10); // Dies
		Zombie.attack("Ghost");
		Zombie.beRepaired(5);
	}
	std::cout << std::endl;

	std::cout << "=== Test 9: Mixed Actions ===" << std::endl;
	{
		ClapTrap Warrior("Warrior");
		Warrior.attack("Enemy");
		Warrior.takeDamage(4);
		Warrior.beRepaired(2);
		Warrior.attack("Boss");
		Warrior.takeDamage(8);
		Warrior.attack("Boss"); // Should fail (dead)
	}
	std::cout << std::endl;

	return 0;
}
