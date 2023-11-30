#pragma once

#include "SDL.h"

#define KEY_PRESS_SURFACE_TOTAL 1

class Ventana
{
private:

public:
    Ventana(/* args */) {}
    SDL_Window* gWindow = NULL;
    SDL_Surface* gScreenSurface = NULL;
    bool init();
    bool loadMedia();
    void close();
    SDL_Surface* loadSurface( std::string path );
    SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
    SDL_Surface* gCurrentSurface = NULL;
    SDL_Window* gWindow = nullptr;
    SDL_Surface* gScreenSurface = nullptr;
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    void imprimePuntos(double a, double b);
    int SDL_main(int argc, char* args[]);
    ~Ventana() {}
};