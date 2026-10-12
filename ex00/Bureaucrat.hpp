#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string   _name;
		int                 _grade;

	public:
		// Forme canonique
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		// Constructeur avec paramètres
		Bureaucrat(const std::string& name, int grade);

		// Getters
		const std::string&  getName() const;
		int                 getGrade() const;

		// Modifier le grade
		void                incrementGrade();
		void                decrementGrade();

		// Exceptions imbriquées
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
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif