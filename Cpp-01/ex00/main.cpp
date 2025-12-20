#include "Zombie.hpp"

int main(void)
{

	std::cout << "--- Creating zombie on HEAP ---" << std::endl;
	Zombie* heapZombie = newZombie("HeapZombie");

	heapZombie->announce();

	std::cout << std::endl << "--- Creating zombie on STACK ---" << std::endl;
	randomChump("StackZombie");

	std::cout << std::endl << "--- Creating another HEAP zombie ---" << std::endl;
	Zombie* anotherHeap = newZombie("AnotherHeap");

	anotherHeap->announce();

	std::cout << std::endl << "--- Deleting HEAP zombies ---" << std::endl;
	delete heapZombie;
	delete anotherHeap;

	std::cout << std::endl << "--- Program finished ---" << std::endl;

	return 0;
}

