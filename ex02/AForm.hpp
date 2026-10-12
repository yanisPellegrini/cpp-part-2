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
		// NOUVEAU (ex02) : l'action propre a chaque formulaire.
		// "= 0" => fonction virtuelle pure => AForm devient abstraite (non instanciable).
		// Chaque classe concrete DOIT la redefinir.
		virtual void		executeAction() const = 0;

	public:
		AForm();
		AForm(const std::string& name, int gradeTS, int gradeTE);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();	// virtual : obligatoire des qu'on fait "delete" via un AForm*

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
		// NOUVEAU (ex02) : execution d'un formulaire non signe
		class FormNotSignedException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
