#include "Bureaucrat.hpp"
#include <iostream>


Bureaucrat::Bureaucrat() : _name("Default"), _grade("Default") {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_name = other._name;
		_grade = other._grade;
	}
	return *this;
}

std::string Bureaucrat::GetName() const {
	return _name;
}

std::string Bureaucrat::GetGrade() const {
	return _grade;
}

Bureaucrat &operator<<(const Bureaucrat& other) {
		std::cout << "Name: " << other.GetName() << ", Grade: " << other.GetGrade() << std::endl;
		return *this;
}
