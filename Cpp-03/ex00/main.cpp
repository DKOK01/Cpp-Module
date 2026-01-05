#include "ClapTrap.hpp"

int main() {
	
	std::cout << "=== Test 1: Attack Function ===" << std::endl;
	{
		ClapTrap clap2("Attacker");
		clap2.attack("Target1");
		clap2.attack("Target2");
		clap2.attack("Target3");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: Take Damage ===" << std::endl;
	{
		ClapTrap clap3("Tank");
		clap3.takeDamage(3);
		clap3.takeDamage(5);
		clap3.takeDamage(10); // Should be destroyed
		clap3.takeDamage(5);  // Already destroyed
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: Repair Function ===" << std::endl;
	{
		ClapTrap clap4("Healer");
		clap4.takeDamage(5);
		clap4.beRepaired(3);
		clap4.beRepaired(3); // Should not exceed max hit points
		clap4.beRepaired(5); // Should not exceed max hit points
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Energy Depletion (Attack) ===" << std::endl;
	{
		ClapTrap clap5("Exhausted");
		for (int i = 0; i < 12; i++) {
			clap5.attack("Enemy");
		}
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: Energy Depletion (Repair) ===" << std::endl;
	{
		ClapTrap clap6("Tired");
		clap6.takeDamage(9);
		for (int i = 0; i < 11; i++) {
			clap6.beRepaired(1);
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
