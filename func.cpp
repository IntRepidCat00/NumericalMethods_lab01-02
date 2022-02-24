#include "func.h"
#include <cmath>
#include <iostream>

long double functionOfX(long double x)
{
    return (x*x*x - 6*x*x - 7);
}

long double firstDerivative(long double x)
{
    return (3*x*x - 12*x);
}

long double secondDerivative(long double x)
{
    return  (6*x-12);
}

void dichotomy(long double a, long double b, long double eps)
{
    long double x, f_x, f_a, f_b;
    f_a = functionOfX(a);
    f_b = functionOfX(b);

    if(f_a*f_b > 0)
    {
        std::cout << "Wrong values of a and b" << std::endl;
        return;
    }

    int iter = 0;
    while((b-a) > eps)
    {
        iter++;
        x = (a+b)/2;
        f_x = functionOfX(x);
        f_a = functionOfX(a);
        f_b = functionOfX(b);

        if(f_x*f_a > 0)
        {
            a = x;
        }

        if(f_x*f_b > 0)
        {
            b = x;
        }

        std::cout << iter << ". " <<  "| a = " << a << " | b = " << b << " | x = " << x << " | f(x) = " << f_x << " |" << std::endl;
    }
}

void hordes(long double a, long double b, long double eps)
{
   if(functionOfX(a)*functionOfX(b) > 0)
   {
       std::cout << "Wrong values of a and b" << std::endl;
       return;
   }

   long double c, s;

   if(firstDerivative(a)* secondDerivative(a) > 0)
   {
       c = b;
       s = a;
   } else
   {
       c = a;
       s = b;
   }

    long double prev;
    int iter = 0;
    while(true)
    {

        iter++;
        prev = c;
        c = c - (functionOfX(c)*(s-c))/(functionOfX(s)- functionOfX(c));
        if(fabs(c-prev) < eps)
        {
            break;
        }
        std::cout << iter << ". | x = " << c << " | f(x) = " << functionOfX(c) << " | " << std::endl;
    }
}