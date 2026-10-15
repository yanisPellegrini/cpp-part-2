#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static void title(const std::string& s)
{
	std::cout << std::endl << "===== " << s << " =====" << std::endl;
}

int main()
{
	std::srand(std::time(0));

	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat intern("Intern", 150);

	// ---------- Affichage ----------
	title("Test 1 : les trois formulaires et leurs grades");
	{
		ShrubberyCreationForm s("home");
		RobotomyRequestForm r("Bender");
		PresidentialPardonForm p("Arthur");
		std::cout << s << std::endl << r << std::endl << p << std::endl;
	}

	// ---------- Shrubbery ----------
	title("Test 2 : Shrubbery signe + execute (cree home_shrubbery)");
	{
		ShrubberyCreationForm s("home");
		mid.signForm(s);
		mid.executeForm(s);
	}

	// ---------- Execution sans signature ----------
	title("Test 3 : executer un formulaire NON signe");
	{
		ShrubberyCreationForm s("garden");
		boss.executeForm(s);
	}

	// ---------- Grade trop bas pour executer ----------
	title("Test 4 : signe, mais grade trop bas pour executer");
	{
		Bureaucrat signer("Signer", 70);	// peut signer (72) mais pas executer (45)
		RobotomyRequestForm r("Bender");
		signer.signForm(r);
		signer.executeForm(r);
	}

	title("Test 5 : grade trop bas pour signer");
	{
		PresidentialPardonForm p("Arthur");
		intern.signForm(p);
		intern.executeForm(p);
	}

	// ---------- Robotomy (50%) ----------
	title("Test 6 : Robotomy execute 4 fois (environ 50% de reussite)");
	{
		RobotomyRequestForm r("Bender");
		boss.signForm(r);
		for (int i = 0; i < 4; i++)
			boss.executeForm(r);
	}

	// ---------- Presidential ----------
	title("Test 7 : Presidential pardon");
	{
		PresidentialPardonForm p("Arthur Dent");
		boss.signForm(p);
		boss.executeForm(p);
	}

	title("Test 8 : grade exactement egal au grade d'execution (5 / 5)");
	{
		Bureaucrat exact("Exact", 5);
		PresidentialPardonForm p("Ford");
		exact.signForm(p);
		exact.executeForm(p);
	}

	title("Test 9 : grade juste en dessous (6 / 5)");
	{
		Bureaucrat almost("Almost", 6);
		PresidentialPardonForm p("Ford");
		boss.signForm(p);
		almost.executeForm(p);
	}

	// ---------- Polymorphisme ----------
	title("Test 10 : via un pointeur AForm* (polymorphisme)");
	{
		AForm* forms[3];
		forms[0] = new ShrubberyCreationForm("office");
		forms[1] = new RobotomyRequestForm("Marvin");
		forms[2] = new PresidentialPardonForm("Zaphod");
		for (int i = 0; i < 3; i++)
		{
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
		}
		for (int i = 0; i < 3; i++)
			delete forms[i];	// appelle le bon destructeur grace a virtual ~AForm()
	}

	// ---------- execute() direct ----------
	title("Test 11 : execute() appele directement (exception remonte au main)");
	try
	{
		PresidentialPardonForm p("Arthur");
		p.execute(boss);	// non signe
		std::cout << "ERREUR : cette ligne ne devrait pas s'afficher" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// ---------- Copie ----------
	title("Test 12 : copie et affectation");
	{
		RobotomyRequestForm a("A");
		boss.signForm(a);
		RobotomyRequestForm copy(a);
		std::cout << "Copy:    " << copy << " (target " << copy.getTarget() << ")" << std::endl;
		RobotomyRequestForm b("B");
		b = a;
		std::cout << "B = A -> " << b << " (target " << b.getTarget() << ")" << std::endl;
	}

	// AForm f;  // ne doit PAS compiler : AForm est abstraite

	return 0;
}
