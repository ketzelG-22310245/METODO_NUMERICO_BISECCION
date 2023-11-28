#ifndef VENTANA_HPP
#define VENTANA_HPP

#include <SDL.h>

class Ventana
{
private:
    /* data */
public:
    Ventana(/* args */) {}
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    ~Ventana() {}
};

#endif