#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <iostream>
#include <NumericalMethod.hpp>
#include <BisectionMethod.hpp>

int main(int argc, char **argv) {
    BisectionMethod bisectionMethod;
    NumericalMethod numericalMethod;

    numericalMethod.run(bisectionMethod);

    return 0;
}