#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void title(const std::string& s)
{
	std::cout << std::endl << "===== " << s << " =====" << std::endl;
}

int main()
{
	// ---------- Construction de Form ----------
	title("Test 1 : construction valide + affichage");
	try
	{
		Form f("Form28B", 50, 25);
		std::cout << f << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Test 2 : limites valides (1 et 150)");
	try
	{
		Form top("TopSecret", 1, 1);
		Form low("Easy", 150, 150);
		std::cout << top << std::endl;
		std::cout << low << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Test 3 : grade pour signer = 0 (trop haut)");
	try
	{
		Form f("Bad", 0, 50);
		std::cout << "ERREUR : cette ligne ne devrait pas s'afficher" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Test 4 : grade pour executer = 151 (trop bas)");
	try
	{
		Form f("Bad", 50, 151);
		std::cout << "ERREUR : cette ligne ne devrait pas s'afficher" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Test 5 : catch par type precis (Form:: et pas Bureaucrat::)");
	try
	{
		Form f("Bad", 200, 50);
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "ERREUR : attrape comme une exception de Bureaucrat" << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << "Caught Form::GradeTooLowException: " << e.what() << std::endl;
	}

	// ---------- signForm ----------
	title("Test 6 : signature reussie (grade 10 >= requis 50)");
	{
		Bureaucrat boss("Boss", 10);
		Form f("Form28B", 50, 25);
		std::cout << "Before: " << f << std::endl;
		boss.signForm(f);
		std::cout << "After:  " << f << std::endl;
	}

	title("Test 7 : signature ratee (grade 100 < requis 50)");
	{
		Bureaucrat intern("Intern", 100);
		Form f("Form28B", 50, 25);
		intern.signForm(f);
		std::cout << "Still:  " << f << std::endl;
	}

	title("Test 8 : grade EXACTEMENT egal au grade requis (50 / 50)");
	{
		Bureaucrat exact("Exact", 50);
		Form f("Form28B", 50, 25);
		exact.signForm(f);
		std::cout << f << std::endl;
	}

	title("Test 9 : grade juste en dessous (51 / 50)");
	{
		Bureaucrat almost("Almost", 51);
		Form f("Form28B", 50, 25);
		almost.signForm(f);
		std::cout << f << std::endl;
	}

	title("Test 10 : rate, puis promotion, puis reussi");
	{
		Bureaucrat jim("Jim", 51);
		Form f("Form28B", 50, 25);
		jim.signForm(f);
		jim.incrementGrade();
		std::cout << jim << std::endl;
		jim.signForm(f);
		std::cout << f << std::endl;
	}

	// ---------- beSigned directement ----------
	title("Test 11 : beSigned appele directement (exception remonte au main)");
	try
	{
		Bureaucrat low("Low", 150);
		Form f("Form28B", 50, 25);
		f.beSigned(low);
		std::cout << "ERREUR : cette ligne ne devrait pas s'afficher" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// ---------- Forme canonique ----------
	title("Test 12 : constructeur par defaut");
	{
		Form def;
		std::cout << def << std::endl;
	}

	title("Test 13 : copie et affectation");
	{
		Bureaucrat boss("Boss", 1);
		Form signedForm("A", 10, 10);
		boss.signForm(signedForm);

		Form copy(signedForm);
		std::cout << "Copy:     " << copy << std::endl;

		Form other("B", 100, 100);
		std::cout << "Before:   " << other << std::endl;
		other = signedForm;
		std::cout << "B = A ->  " << other << std::endl;
	}

	return 0;
}
