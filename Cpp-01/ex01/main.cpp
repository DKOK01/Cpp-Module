#include "Zombie.hpp"

int main(void)
{
	int hordeSize = 5;

	std::cout << "=== Creating a horde of " << hordeSize << " zombies ===" << std::endl;
	Zombie* horde = zombieHorde(hordeSize, "Walker");

	std::cout << std::endl << "=== All zombies announcing ===" << std::endl;
	for (int i = 0; i < hordeSize; i++)
	{
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}

	std::cout << std::endl << "=== Deleting the horde ===" << std::endl;
	delete[] horde;

	std::cout << std::endl << "=== Done ===" << std::endl;

	return 0;
}

