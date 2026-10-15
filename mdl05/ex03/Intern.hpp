#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	private:
		// NOUVEAU (ex03) : une fonction de creation par formulaire.
		// "static" : elles n'ont pas besoin d'un objet Intern (pas de this),
		// donc on peut les ranger dans un tableau de pointeurs sur fonctions classiques.
		static AForm*	createShrubbery(const std::string& target);
		static AForm*	createRobotomy(const std::string& target);
		static AForm*	createPresidential(const std::string& target);

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		// NOUVEAU (ex03) : renvoie un formulaire alloue avec new (a delete par l'appelant),
		// ou NULL si le nom est inconnu.
		AForm*			makeForm(const std::string& formName, const std::string& target) const;
};

#endif
