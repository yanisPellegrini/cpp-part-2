#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <string>

// Grades requis : sign 25, exec 5
class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;

	protected:
		virtual void		executeAction() const;	// A IMPLEMENTER

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();

		const std::string&	getTarget() const;
};

#endif
