#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeTS;
		const int			_gradeTE;

	protected:
		virtual void		executeAction() const = 0;

	public:
		AForm();
		AForm(const std::string& name, int gradeTS, int gradeTE);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		const std::string&	getName() const;
		bool				isSigned() const;
		int					getGradeTS() const;
		int					getGradeTE() const;

		void				beSigned(const Bureaucrat& b);
		void				execute(Bureaucrat const & executor) const;	// NOUVEAU (ex02)

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
