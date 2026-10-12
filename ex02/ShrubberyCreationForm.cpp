#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);	// _target est const : on ne copie que la partie AForm
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string& ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::executeAction() const {
	// TODO (ex02)
	//  - creer le fichier "<_target>_shrubbery" : std::ofstream, nom = (_target + "_shrubbery").c_str()  (C++98 !)
	//  - verifier que le fichier est bien ouvert (sinon : message d erreur ou exception)
	//  - ecrire des arbres en ASCII dedans avec <<
	//  - le fichier se ferme tout seul a la fin (destructeur de ofstream)
}
