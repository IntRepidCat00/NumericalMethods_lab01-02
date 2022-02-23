#include <iostream>
#include "func.h"

int main()
{
    std::cout << "===================================================================" << std::endl;
    std::cout << "Dichotomy: " << std::endl;
    dichotomy(0.5, 1, 10e-3);
    std::cout << "===================================================================" << std::endl;
    std::cout << "Hordes: " << std::endl;
    hordes(0.5, 1, 10e-3);
    std::cout << "===================================================================" << std::endl;
    return 0;
}
