#include "func.h"
#include <cmath>
#include <iostream>

void dichotomy(long double a, long double b, long double eps)
{
    long double x, f_x, f_a, f_b;
    f_a = a + log(a) - 0.5;
    f_b = b + log(b) - 0.5;

    if(f_a*f_b > 0)
    {
        std::cout << "Wrong values of a and b" << std::endl;
        return;
    }

    while((b-a) > eps)
    {
        x = (a+b)/2;
        f_x = x + log(x) - 0.5;
        f_a = a + log(a) - 0.5;
        f_b = b + log(b) - 0.5;

        if(f_x*f_a > 0)
        {
            a = x;
        }

        if(f_x*f_b > 0)
        {
            b = x;
        }

        std::cout << "| a = " << a << " | b = " << b << " | x = " << x << " | f(x) = " << f_x << " |" << std::endl;
    }
}

void hordes(long double a, long double b, long double eps)
{
   long double f_AII = 1 + 1/a;
   long double f_A = a + log(a) - 0.5;
   long double f_B = b + log(b) - 0.5;

   long double c, s, f_c, f_s;

   if(f_A*f_B > 0)
   {
       std::cout << "Wrong values of a and b" << std::endl;
       return;
   }
   if(f_A*f_AII > 0)
   {
       c = a;
       f_c = f_A;
       s = b;
       f_s = f_B;
   } else
   {
       c = b;
       f_c = f_B;
       s = a;
       f_s = f_A;
   }


    long double cprev;
    do
    {
        cprev = c;
        c = c - ((f_c)*(s-c))/(f_s-f_c);
        f_c = c + log(c) - 0.5;
        std::cout << "| x = " << c << " | f(x) = " << f_c << std::endl;
    } while(fabs(c - cprev) > eps);

}