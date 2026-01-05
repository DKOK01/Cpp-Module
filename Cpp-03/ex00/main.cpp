#include "ClapTrap.hpp"

int main() {
	std::cout << "=== Test 1: Basic Construction and Destruction ===" << std::endl;
	{
		ClapTrap clap1("Robot1");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: Attack Function ===" << std::endl;
	{
		ClapTrap clap2("Attacker");
		clap2.attack("Target1");
		clap2.attack("Target2");
		clap2.attack("Target3");
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: Take Damage ===" << std::endl;
	{
		ClapTrap clap3("Damaged");
		clap3.takeDamage(3);
		clap3.takeDamage(5);
		clap3.takeDamage(10); // Should be destroyed
		clap3.takeDamage(5);  // Already destroyed
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Repair Function ===" << std::endl;
	{
		ClapTrap clap4("Healer");
		clap4.takeDamage(5);
		clap4.beRepaired(3);
		clap4.beRepaired(2);
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: Energy Depletion (Attack) ===" << std::endl;
	{
		ClapTrap clap5("Exhausted");
		for (int i = 0; i < 12; i++) {
			clap5.attack("Enemy");
		}
	}
	std::cout << std::endl;

	std::cout << "=== Test 6: Energy Depletion (Repair) ===" << std::endl;
	{
		ClapTrap clap6("Tired");
		for (int i = 0; i < 11; i++) {
			clap6.beRepaired(1);
		}
	}
	std::cout << std::endl;

	std::cout << "=== Test 7: Dead ClapTrap Cannot Act ===" << std::endl;
	{
		ClapTrap clap7("Zombie");
		clap7.takeDamage(10); // Dies
		clap7.attack("Ghost");
		clap7.beRepaired(5);
	}
	std::cout << std::endl;

	std::cout << "=== Test 8: Copy Constructor ===" << std::endl;
	{
		ClapTrap clap8("Original");
		clap8.takeDamage(3);
		ClapTrap clap9(clap8);
		clap9.attack("CopyTarget");
	}
	std::cout << std::endl;

	std::cout << "=== Test 9: Assignment Operator ===" << std::endl;
	{
		ClapTrap clap10("First");
		ClapTrap clap11("Second");
		clap10.takeDamage(2);
		clap11 = clap10;
		clap11.attack("AssignTarget");
	}
	std::cout << std::endl;

	std::cout << "=== Test 10: Mixed Actions ===" << std::endl;
	{
		ClapTrap clap12("Warrior");
		clap12.attack("Enemy1");
		clap12.takeDamage(4);
		clap12.beRepaired(2);
		clap12.attack("Enemy2");
		clap12.takeDamage(8);
		clap12.attack("Enemy3"); // Should fail (dead)
	}
	std::cout << std::endl;

	return 0;
}
