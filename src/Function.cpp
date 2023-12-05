#include <Function.hpp>
#include <cmath>
#include <iostream>
#include <cstdlib>

double Function::evaluar(double x)
{
    return x - 4 * sin(x);
}