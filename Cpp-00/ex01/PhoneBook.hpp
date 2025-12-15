#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_contactCount;
	int		_oldestIndex;

	std::string	_formatField(const std::string& field) const;
	void		_displayContactRow(int index) const;
	void		_displayContactDetails(int index) const;

public:
	PhoneBook();
	~PhoneBook();

	void	addContact(const Contact& contact);
	void	searchContacts() const;
};

#endif
