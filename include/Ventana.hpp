#pragma once

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <iostream>
#include <iomanip>
#include <Biseccion.hpp>
#include <Constants.hpp>

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

SDL_Window* Ventana::gWindow = nullptr;
SDL_Surface* Ventana::gScreenSurface = nullptr;

const int Ventana::SCREEN_WIDTH;
const int Ventana::SCREEN_HEIGHT;

Ventana::Ventana(){

}

Ventana::~Ventana(){
    
}

bool Ventana::init()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
        // Create window
        gWindow = SDL_CreateWindow("Metodo de biseccion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr)
        {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            return false;
        }
            // Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);

            return true;
        }

bool Ventana::loadMedia()
{
    
}

void Ventana::close()
{
    SDL_DestroyWindow(Ventana::gWindow);

    // Quit SDL
    SDL_Quit();
}

SDL_Surface *Ventana::loadSurface(std::string path)
{
    // Implementación de la función loadSurface
}

void Ventana::imprimePuntos(double a, double b)
{

}
