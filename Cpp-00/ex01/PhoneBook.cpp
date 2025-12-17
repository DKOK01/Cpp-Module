#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

std::string	PhoneBook::formatField(const std::string& field) const
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void	PhoneBook::displayContactRow(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << formatField(contacts[index].getFirstName());
	std::cout << "|" << std::setw(10) << formatField(contacts[index].getLastName());
	std::cout << "|" << std::setw(10) << formatField(contacts[index].getNickname());
	std::cout << "|" << std::endl;
}

void	PhoneBook::displayContactDetails(int index) const
{
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::addContact(const Contact& contact)
{
	if (contactCount < 8)
	{
		contacts[contactCount] = contact;
		contactCount++;
	}
	else
	{
		contacts[oldestIndex] = contact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
}

void	PhoneBook::searchContacts() const
{
	if (contactCount == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}

	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;

	for (int i = 0; i < contactCount; i++)
	{
		if (!contacts[i].isEmpty())
			displayContactRow(i);
	}

	std::cout << "Enter index of contact to display: ";
	std::string input;
	std::getline(std::cin, input);

	if (std::cin.eof())
		return;

	std::stringstream ss(input);
	int index;
	
	if (!(ss >> index) || !(ss.eof()))
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	if (index < 0 || index >= contactCount || contacts[index].isEmpty())
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	displayContactDetails(index);
}
