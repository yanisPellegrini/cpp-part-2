#include "AForm.hpp"
#include <iostream>

AForm::AForm() : _name("Default"), _isSigned(false), _gradeTS(150), _gradeTE(150) {}

AForm::~AForm() {}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeTS(other._gradeTS), _gradeTE(other._gradeTE) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::AForm(const std::string& name, int gradeTS, int gradeTE) : _name(name), _isSigned(false), _gradeTS(gradeTS), _gradeTE(gradeTE) {
	if (gradeTS < 1 || gradeTE < 1) {
		throw GradeTooHighException();
	} else if (gradeTS > 150 || gradeTE > 150) {
		throw GradeTooLowException();
	}
}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _isSigned;
}

int AForm::getGradeTS() const {
	return _gradeTS;
}

int AForm::getGradeTE() const {
	return _gradeTE;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _gradeTS) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!_isSigned) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > _gradeTE) {
		throw GradeTooLowException();
	}
	executeAction();
	(void)executor;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "Form Name: " << f.getName()
	   << ", Signed: " << (f.isSigned() ? "Yes" : "No")
	   << ", Grade to Sign: " << f.getGradeTS()
	   << ", Grade to Execute: " << f.getGradeTE();
	return os;
}
