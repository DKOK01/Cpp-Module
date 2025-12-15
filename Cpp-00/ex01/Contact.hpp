#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>


class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	Contact();
	~Contact();

	void		setFirstName(const std::string& firstName);
	void		setLastName(const std::string& lastName);
	void		setNickname(const std::string& nickname);
	void		setPhoneNumber(const std::string& phoneNumber);
	void		setDarkestSecret(const std::string& darkestSecret);

	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;

	bool		isEmpty() const;
};

#endif
/*

The constructor creates and initializes a Contact object with empty values.
It's called automatically whenever we create a Contact, like when we declare the contacts array in PhoneBook.cpp:

The destructor is called automatically when a Contact object is destroyed.
It ensures all resources are properly cleaned up, especially the std::string members.
*/