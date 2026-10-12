#include "Form.hpp"
#include <iostream>

Form::Form() : _name("Default"), _isSigned(false), _gradeTS(150), _gradeTE(150) {}

Form::~Form() {}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeTS(other._gradeTS), _gradeTE(other._gradeTE) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::Form(const std::string& name, int gradeTS, int gradeTE) : _name(name), _isSigned(false), _gradeTS(gradeTS), _gradeTE(gradeTE) {
	if (gradeTS < 1 || gradeTE < 1) {
		throw GradeTooHighException();
	} else if (gradeTS > 150 || gradeTE > 150) {
		throw GradeTooLowException();
	}
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _isSigned;
}

int Form::getGradeTS() const {
	return _gradeTS;
}

int Form::getGradeTE() const {
	return _gradeTE;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _gradeTS) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form Name: " << f.getName()
	   << ", Signed: " << (f.isSigned() ? "Yes" : "No")
	   << ", Grade to Sign: " << f.getGradeTS()
	   << ", Grade to Execute: " << f.getGradeTE();
	return os;
}
