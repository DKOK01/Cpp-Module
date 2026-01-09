#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n\n=== Test 1: Basic Polymorphism ===" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "\nType tests:" << std::endl;
        std::cout << "Meta type: " << meta->getType() << std::endl;
		std::cout << "Dog type: " << j->getType() << " " << std::endl;
		std::cout << "Cat type: " << i->getType() << " " << std::endl;

		std::cout << "\nSound tests:" << std::endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound(); // will output the dog sound!
		meta->makeSound();

		std::cout << "\nCleanup:" << std::endl;
		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\n\n\n=== Test 2: Wrong Animal (no polymorphism) ===" << std::endl;
	{
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();

		std::cout << "\nType tests:" << std::endl;
		std::cout << "WrongCat type: " << wrongCat->getType() << " " << std::endl;

		std::cout << "\nSound tests (should output WrongAnimal sound):" << std::endl;
		wrongCat->makeSound(); // will output the WrongAnimal sound
		wrongMeta->makeSound();

		std::cout << "\nCleanup:" << std::endl;
		delete wrongMeta;
		delete wrongCat;
	}

	return 0;
}
