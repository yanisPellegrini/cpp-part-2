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
	// TODO (ex02)
	//  - afficher des bruits de perceuse ("* DRILLING NOISES *")
	//  - 50% du temps (std::rand() % 2) : "<_target> has been robotomized successfully"
	//  - sinon : "Robotomy on <_target> failed"
	//  (std::srand(std::time(0)) est deja appele une fois dans le main)
}
