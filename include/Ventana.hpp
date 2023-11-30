#pragma once
#include <string>
#include <iostream>
#include "SDL.h"

#define KEY_PRESS_SURFACE_TOTAL 1

class Ventana
{
private:
    SDL_Window *gWindow;
    SDL_Surface *gScreenSurface;
    SDL_Surface *gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
    SDL_Surface *gCurrentSurface;

public:
    Ventana() : gWindow(nullptr), gScreenSurface(nullptr), gCurrentSurface(nullptr) {}
    ~Ventana() {}

    bool init();
    bool loadMedia();
    void close();
    SDL_Surface *loadSurface(std::string path);
    void imprimePuntos(double a, double b);
};