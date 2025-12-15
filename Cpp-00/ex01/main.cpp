#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

static std::string	getInput(const std::string& prompt)
{
	std::string input;

	while (input.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit(0);
		}
		
		if (input.empty())
			std::cout << "Field cannot be empty!" << std::endl;
	}
	return input;
}

static void	addContact(PhoneBook& phoneBook)
{
	Contact contact;

	contact.setFirstName(getInput("First Name: "));
	contact.setLastName(getInput("Last Name: "));
	contact.setNickname(getInput("Nickname: "));
	contact.setPhoneNumber(getInput("Phone Number: "));
	contact.setDarkestSecret(getInput("Darkest Secret: "));

	phoneBook.addContact(contact);
	std::cout << "Contact added successfully!" << std::endl;
}

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}

		if (command == "ADD")
			addContact(phoneBook);
		else if (command == "SEARCH")
			phoneBook.searchContacts();
		else if (command == "EXIT")
			break;
		else if (!command.empty())
			std::cout << "Invalid command! Use ADD, SEARCH, or EXIT." << std::endl;
	}

	std::cout << "Goodbye!" << std::endl;
	return 0;
}
