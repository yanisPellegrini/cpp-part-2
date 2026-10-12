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
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs.is_open())
		throw std::runtime_error("Failed to open file " + _target + "_shrubbery");
	if (ofs.fail())
		throw std::runtime_error("Failed to write to file " + _target + "_shrubbery");
	ofs << "            .        +          .      .          ." << std::endl;
	ofs << "     .            _        .                    ." << std::endl;
	ofs << "  ,              /;-._,-.____        ,-----.__" << std::endl;
	ofs << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
	ofs << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
	ofs << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
	ofs << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
	ofs << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
	ofs << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
	ofs << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
	ofs << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
	ofs << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
	ofs << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
	ofs << "                    \\::.  :\\/:'  /              +" << std::endl;
	ofs << "   .                 `.:.  /:'  }      ." << std::endl;
	ofs << "           .           ):_(:;   \\           ." << std::endl;
	ofs << "                      /:. _/ ,  |" << std::endl;
	ofs << "                   . (|::.     ,`                  ." << std::endl;
	ofs << "     .                |::.    {\\" << std::endl;
	ofs << "                      |::.\\  \\ `." << std::endl;
	ofs << "                      |:::(\\    |" << std::endl;
	ofs << "              O       |:::/{ }  |                  (o" << std::endl;
	ofs << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
	ofs << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
	ofs << "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << std::endl;
	ofs.close();
}
