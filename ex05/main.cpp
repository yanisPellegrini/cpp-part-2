#include "Bureaucrat.h"
#include <iostream>

int main()
{
	Bureaucrat bureaucrat;
	std::cout << "Name: " << bureaucrat.GetName() << std::endl;
	std::cout << "Grade: " << bureaucrat.GetGrade() << std::endl;
    return 0;
}
