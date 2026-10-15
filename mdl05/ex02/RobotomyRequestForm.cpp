#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);	// _target est const : on ne copie que la partie AForm
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string& RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::executeAction() const {

	std::cout << "* DRILLING NOISES *" << std::endl;
	int randomValue = std::rand() % 2;
	if (randomValue == 0) {
		std::cout << _target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "Robotomy on " << _target << " failed." << std::endl;
	}
}
