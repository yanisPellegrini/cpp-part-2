#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>

// Grades requis : sign 72, exec 45
class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;

	protected:
		virtual void		executeAction() const;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();

		const std::string&	getTarget() const;
};

#endif
