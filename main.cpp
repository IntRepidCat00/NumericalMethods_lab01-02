#include <iostream>
#include "func.h"

int main()
{
    long double a, b, eps;
    std::cout << "Enter eps:" << std::endl;
    std::cin >> eps;
    std::cout << "Enter left border 'a':" <<std::endl;
    std::cin >> a;
    std::cout << "Enter right border 'b':" <<std::endl;
    std::cin >> b;

    std::cout << "===================================================================" << std::endl;
    std::cout << "Dichotomy: " << std::endl;
    dichotomy(a, b, eps);
    std::cout << "===================================================================" << std::endl;
    std::cout << "Hordes: " << std::endl;
    hordes(a, b, eps);
    std::cout << "===================================================================" << std::endl;
    std::cout << "Newton: " << std::endl;
    newton(a, b, eps);
    std::cout << "===================================================================" << std::endl;
    std::cout << "Iterations: " << std::endl;
    iterations(a, b, eps);
    std::cout << "===================================================================" << std::endl;
    return 0;
}
