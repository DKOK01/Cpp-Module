#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n\n=== Test 1: Basic test from subject ===" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "\nDeleting (should not create a leak):" << std::endl;
		delete j;
		delete i;
	}


	std::cout << "\n\n\n=== Test 2: Array of Animals (half Dogs, half Cats) ===" << std::endl;
	{
		const int arraySize = 10;
		Animal* animals[arraySize];

		std::cout << "\nCreating animals array:" << std::endl;
		for (int i = 0; i < arraySize; i++) {
			if (i < arraySize / 2) {
				animals[i] = new Dog();
			} else {
				animals[i] = new Cat();
			}
		}

		std::cout << "\nAll animals making sounds:" << std::endl;
		for (int i = 0; i < arraySize; i++) {
			std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
			animals[i]->makeSound();
		}

		std::cout << "\nDeleting animals as Animal*:" << std::endl;
		for (int i = 0; i < arraySize; i++) {
			delete animals[i];
		}
	}


	std::cout << "\n\n\n=== Test 3: Deep copy test with Dog ===" << std::endl;
	{
		Dog dog1;
		dog1.getBrain()->setIdea(0, "I want to chase the ball!");
		dog1.getBrain()->setIdea(1, "I love my owner!");
		dog1.getBrain()->setIdea(2, "Time for a walk!");

		std::cout << "\nDog1 ideas:" << std::endl;
		std::cout << "Idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea 1: " << dog1.getBrain()->getIdea(1) << std::endl;
		std::cout << "Idea 2: " << dog1.getBrain()->getIdea(2) << std::endl;

		std::cout << "\nCreating dog2 as a copy of dog1:" << std::endl;
		Dog dog2(dog1);

		std::cout << "\nDog2 ideas (should be same as dog1):" << std::endl;
		std::cout << "Idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea 1: " << dog2.getBrain()->getIdea(1) << std::endl;
		std::cout << "Idea 2: " << dog2.getBrain()->getIdea(2) << std::endl;

		std::cout << "\nModifying dog2's ideas:" << std::endl;
		dog2.getBrain()->setIdea(0, "I want to sleep!");
		dog2.getBrain()->setIdea(1, "Where is my food?");

		std::cout << "\nDog1 ideas (should be UNCHANGED - deep copy):" << std::endl;
		std::cout << "Idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea 1: " << dog1.getBrain()->getIdea(1) << std::endl;

		std::cout << "\nDog2 ideas (should be CHANGED):" << std::endl;
		std::cout << "Idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea 1: " << dog2.getBrain()->getIdea(1) << std::endl;

		std::cout << "\nBrain addresses (should be DIFFERENT):" << std::endl;
		std::cout << "Dog1 brain: " << dog1.getBrain() << std::endl;
		std::cout << "Dog2 brain: " << dog2.getBrain() << std::endl;

		std::cout << "\nCleanup:" << std::endl;
	}


	std::cout << "\n\n\n=== Test 4: Deep copy test with Cat ===" << std::endl;
	{
		Cat cat1;
		cat1.getBrain()->setIdea(0, "I want to catch that mouse!");
		cat1.getBrain()->setIdea(1, "Time to knock things off the table!");

		std::cout << "\nCat1 ideas:" << std::endl;
		std::cout << "Idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea 1: " << cat1.getBrain()->getIdea(1) << std::endl;

		std::cout << "\nCreating cat2 as a copy of cat1:" << std::endl;
		Cat cat2(cat1);

		std::cout << "\nModifying cat2's ideas:" << std::endl;
		cat2.getBrain()->setIdea(0, "I need a nap!");

		std::cout << "\nCat1 idea 0 (should be UNCHANGED): " << cat1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Cat2 idea 0 (should be CHANGED): " << cat2.getBrain()->getIdea(0) << std::endl;

		std::cout << "\nBrain addresses (should be DIFFERENT):" << std::endl;
		std::cout << "Cat1 brain: " << cat1.getBrain() << std::endl;
		std::cout << "Cat2 brain: " << cat2.getBrain() << std::endl;

		std::cout << "\nCleanup:" << std::endl;
	}

	
	std::cout << "\n\n\n=== Test 5: Assignment operator deep copy test ===" << std::endl;
	{
		Dog dog1;
		Dog dog2;

		dog1.getBrain()->setIdea(0, "Original dog1 idea");
		dog2.getBrain()->setIdea(0, "Original dog2 idea");

		std::cout << "\nBefore assignment:" << std::endl;
		std::cout << "Dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;

		std::cout << "\nAssigning dog1 to dog2:" << std::endl;
		dog2 = dog1;

		std::cout << "\nAfter assignment:" << std::endl;
		std::cout << "Dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;

		std::cout << "\nModifying dog2's brain after assignment:" << std::endl;
		dog2.getBrain()->setIdea(0, "Modified dog2 idea");

		std::cout << "\nDog1 idea 0 (should be UNCHANGED): " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Dog2 idea 0 (should be CHANGED): " << dog2.getBrain()->getIdea(0) << std::endl;

		std::cout << "\nBrain addresses (should be DIFFERENT):" << std::endl;
		std::cout << "Dog1 brain: " << dog1.getBrain() << std::endl;
		std::cout << "Dog2 brain: " << dog2.getBrain() << std::endl;

		std::cout << "\nCleanup:" << std::endl;
	}

	return 0;
}
