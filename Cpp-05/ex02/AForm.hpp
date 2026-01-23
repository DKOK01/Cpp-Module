#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

	static const int	HIGHEST_GRADE = 1;
	static const int	LOWEST_GRADE = 150;

public:
	// Orthodox Canonical Form
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	// Getters
	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// Member functions
	void			beSigned(const Bureaucrat& bureaucrat);
	void			execute(Bureaucrat const& executor) const;

	// Pure virtual function
	virtual void	executeAction() const = 0;

	// Exception classes
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
