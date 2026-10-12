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
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		const std::string&  getName() const;
		int                 getGrade() const;
		void                incrementGrade();
		void                decrementGrade();

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

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeTS;
        const int _gradeTE;
    public:
        Form();
        Form(const std::string& name, int gradeTS, int gradeTE);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string& getName() const;
        bool isSigned() const;
        int getGradeTS() const;
        int getGradeTE() const;

        void beSigned(const Bureaucrat& b);

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