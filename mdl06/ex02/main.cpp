#include "function.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::srand(std::time(NULL));   // une seule fois, au début

    for (int i = 0; i < 10; i++)
    {
        Base* p = generate();      // affiche "Generate : X"

        std::cout << "pointer   : ";
        identify(p);

        std::cout << "reference : ";
        identify(*p);

        std::cout << std::endl;
        delete p;
    }

    std::cout << "NULL      : ";
    identify(static_cast<Base*>(NULL));
    return 0;
}