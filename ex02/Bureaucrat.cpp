#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1) {
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150) {
		throw GradeTooLowException();
	}
	_grade++;
}

void Bureaucrat::signForm(AForm& f) {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
	// TODO (ex02)
	// Meme principe que signForm :
	//  - try : appeler form.execute(*this), puis afficher "<bureaucrat> executed <form>"
	//  - catch : afficher un message d'erreur explicite avec e.what()
	(void)form;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
