#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <iostream>
#include <NumericalMethod.hpp>
#include <BisectionMethod.hpp>

int main(int argc, char **argv) {
<<<<<<< HEAD
    NumericalMethod numericalMethod;
=======
    BisectionMethod bisectionMethod;
    NumericalMethod numericalMethod(bisectionMethod); // Pasa el objeto BisectionMethod al constructor

>>>>>>> 938b4e6 (ventana abre)
    numericalMethod.run();

    return 0;
}