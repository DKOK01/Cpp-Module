#include <iostream>
#include "Serializer.hpp"

int main() {
	// Create a Data object
	Data original;
	original.name = "Test";
	original.value = 42;

	std::cout << "=== Original Data ===" << std::endl;
	std::cout << "Address: " << &original << std::endl;
	std::cout << "Name: " << original.name << std::endl;
	std::cout << "Value: " << original.value << std::endl;

	// Serialize: pointer → uintptr_t
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "\n=== Serialized ===" << std::endl;
	std::cout << "Raw value: " << raw << std::endl;

	// Deserialize: uintptr_t → pointer
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "\n=== Deserialized ===" << std::endl;
	std::cout << "Address: " << ptr << std::endl;
	std::cout << "Name: " << ptr->name << std::endl;
	std::cout << "Value: " << ptr->value << std::endl;

	// Verify pointers are equal
	std::cout << "\n=== Verification ===" << std::endl;
	if (ptr == &original)
		std::cout << "SUCCESS: Pointers are equal!" << std::endl;
	else
		std::cout << "FAILURE: Pointers are NOT equal!" << std::endl;

	return 0;
}
