
#include "Bureaucrat.hpp"
#include <iostream>

void title(const std::string& s)
{
	std::cout << std::endl << "===== " << s << " =====" << std::endl;
}

int main()
{
	// ---------- Construction ----------
	title("Test 1 : construction valide");
	try
	{
		Bureaucrat bob("Bob", 42);
		std::cout << bob << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Test 2 : limites valides (1 et 150)");
	try
	{
		Bureaucrat top("Top", 1);
		Bureaucrat bottom("Bottom", 150);
		std::cout << top << std::endl;
		std::cout << bottom << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Test 3 : grade 0 (trop haut)");
	try
	{
		Bureaucrat b("Zero", 0);
		std::cout << b << std::endl;
		std::cout << "ERREUR : cette ligne ne devrait pas s'afficher" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Test 4 : grade 151 (trop bas)");
	try
	{
		Bureaucrat b("Loser", 151);
		std::cout << b << std::endl;
		std::cout << "ERREUR : cette ligne ne devrait pas s'afficher" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Test 5 : grade negatif (-42)");
	try
	{
		Bureaucrat b("Negative", -42);
		std::cout << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// ---------- Increment / Decrement ----------
	title("Test 6 : increment normal (3 -> 2)");
	try
	{
		Bureaucrat alice("Alice", 3);
		std::cout << "Before: " << alice << std::endl;
		alice.incrementGrade();
		std::cout << "After:  " << alice << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Test 7 : decrement normal (3 -> 4)");
	try
	{
		Bureaucrat alice("Alice", 3);
		std::cout << "Before: " << alice << std::endl;
		alice.decrementGrade();
		std::cout << "After:  " << alice << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Test 8 : increment d'un grade 1");
	{
		Bureaucrat boss("Boss", 1);
		std::cout << "Before: " << boss << std::endl;
		try
		{
			boss.incrementGrade();
			std::cout << "ERREUR : cette ligne ne devrait pas s'afficher" << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "Still:  " << boss << std::endl;
	}

	title("Test 9 : decrement d'un grade 150");
	{
		Bureaucrat intern("Intern", 150);
		std::cout << "Before: " << intern << std::endl;
		try
		{
			intern.decrementGrade();
			std::cout << "ERREUR : cette ligne ne devrait pas s'afficher" << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "Still:  " << intern << std::endl;
	}

	title("Test 10 : monter de 3 a 1 puis une fois de trop");
	{
		Bureaucrat climber("Climber", 3);
		try
		{
			for (int i = 0; i < 5; i++)
			{
				climber.incrementGrade();
				std::cout << climber << std::endl;
			}
		}
		catch (std::exception & e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "Final:  " << climber << std::endl;
	}

	// ---------- Type precis de l'exception ----------
	title("Test 11 : catch par type precis");
	try
	{
		Bureaucrat b("Precise", 200);
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
	}

	// ---------- Forme canonique ----------
	title("Test 12 : constructeur par defaut");
	{
		Bureaucrat def;
		std::cout << def << std::endl;
	}

	title("Test 13 : copie et affectation");
	{
		Bureaucrat bob("Bob", 42);
		Bureaucrat copy(bob);
		Bureaucrat jim("Jim", 100);

		std::cout << "Original: " << bob << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
		std::cout << "Jim:      " << jim << std::endl;
		jim = bob; 
		std::cout << "Jim = Bob -> " << jim << std::endl;

		copy.incrementGrade();
		std::cout << "Copy incremented: " << copy << std::endl;
		std::cout << "Original intact:  " << bob << std::endl;
	}

	return 0;
}

