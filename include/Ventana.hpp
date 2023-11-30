#ifndef VENTANA_HPP
#define VENTANA_HPP

#pragma once

#include <string>
#include <iostream>
#include "SDL2/SDL.h"

#define KEY_PRESS_SURFACE_TOTAL 3

class Ventana
{
private:
    static SDL_Window* gWindow;
    static SDL_Surface* gScreenSurface;
    SDL_Surface *gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
    SDL_Surface *gCurrentSurface;

public:
    Ventana();
    ~Ventana();

    static bool init();
    static void close();
    static SDL_Surface* loadSurface(std::string path);
    static void imprimePuntos(double a, double b);
    static bool loadMedia();
    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;
};

#endif