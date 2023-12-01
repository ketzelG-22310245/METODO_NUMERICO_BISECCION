#include <iostream>
#include <iomanip>
#include <Ventana.hpp>
#include <Biseccion.hpp>
#include <Constants.hpp>

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
