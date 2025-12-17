#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		contactCount;
	int		oldestIndex;

	std::string	formatField(const std::string& field) const;
	void		displayContactRow(int index) const;
	void		displayContactDetails(int index) const;

public:
	PhoneBook();
	~PhoneBook();

	void	addContact(const Contact& contact);
	void	searchContacts() const;
};

#endif
