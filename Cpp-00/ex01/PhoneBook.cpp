#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}

std::string	PhoneBook::_formatField(const std::string& field) const
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void	PhoneBook::_displayContactRow(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << _formatField(_contacts[index].getFirstName());
	std::cout << "|" << std::setw(10) << _formatField(_contacts[index].getLastName());
	std::cout << "|" << std::setw(10) << _formatField(_contacts[index].getNickname());
	std::cout << "|" << std::endl;
}

void	PhoneBook::_displayContactDetails(int index) const
{
	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::addContact(const Contact& contact)
{
	if (_contactCount < 8)
	{
		_contacts[_contactCount] = contact;
		_contactCount++;
	}
	else
	{
		_contacts[_oldestIndex] = contact;
		_oldestIndex = (_oldestIndex + 1) % 8;
	}
}

void	PhoneBook::searchContacts() const
{
	if (_contactCount == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}

	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;

	for (int i = 0; i < _contactCount; i++)
	{
		if (!_contacts[i].isEmpty())
			_displayContactRow(i);
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

	if (index < 0 || index >= _contactCount || _contacts[index].isEmpty())
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	_displayContactDetails(index);
}
