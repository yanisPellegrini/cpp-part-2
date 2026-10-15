#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
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

	Intern		someRandomIntern;
	Bureaucrat	boss("Boss", 1);

	title("Test 1 : l'exemple du sujet (robotomy request -> Bender)");
	{
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << *rrf << std::endl;
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
	}

	title("Test 2 : shrubbery creation (cree garden_shrubbery)");
	{
		AForm* f = someRandomIntern.makeForm("shrubbery creation", "garden");
		if (f)
		{
			std::cout << *f << std::endl;
			boss.signForm(*f);
			boss.executeForm(*f);
			delete f;
		}
	}

	title("Test 3 : presidential pardon");
	{
		AForm* f = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		if (f)
		{
			std::cout << *f << std::endl;
			boss.signForm(*f);
			boss.executeForm(*f);
			delete f;
		}
	}

	title("Test 4 : nom de formulaire inconnu");
	{
		AForm* f = someRandomIntern.makeForm("coffee request", "Boss");
		if (f == NULL)
			std::cout << "makeForm returned NULL" << std::endl;
		delete f;	// delete NULL est sans danger
	}

	title("Test 5 : nom presque correct (casse differente)");
	{
		AForm* f = someRandomIntern.makeForm("Robotomy Request", "Bender");
		if (f == NULL)
			std::cout << "makeForm returned NULL" << std::endl;
		delete f;
	}

	title("Test 6 : formulaire cree par le stagiaire, bureaucrate trop faible");
	{
		Bureaucrat low("Low", 140);
		AForm* f = someRandomIntern.makeForm("presidential pardon", "Ford");
		if (f)
		{
			low.signForm(*f);
			low.executeForm(*f);
			delete f;
		}
	}

	title("Test 7 : forme canonique de Intern");
	{
		Intern a;
		Intern b(a);
		Intern c;
		c = a;
		AForm* f = b.makeForm("robotomy request", "Marvin");
		AForm* g = c.makeForm("shrubbery creation", "office");
		if (f && g)
			std::cout << "copy and assignment work" << std::endl;
		delete f;
		delete g;
	}

	return 0;
}
