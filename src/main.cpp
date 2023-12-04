#include <iostream>
#include <NumericalMethod.hpp>
#include <BisectionMethod.hpp>

int main(int argc, char **argv) {

    
    BisectionMethod bisectionMethod;
    NumericalMethod numericalMethod(bisectionMethod); // Pasa el objeto BisectionMethod al constructor

    numericalMethod.run();

return 0;
}