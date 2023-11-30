#include "C:\Users\Ketzel\Desktop\METODO_NUMERICO_BISECCION\include\Ventana.hpp"
#include "C:\Users\Ketzel\Desktop\METODO_NUMERICO_BISECCION\include\Biseccion.hpp"
#include <iostream>
#include <iomanip>
#include "C:\Users\Ketzel\Desktop\METODO_NUMERICO_BISECCION\include\Constants.hpp"

SDL_Window* Ventana::gWindow = nullptr;
SDL_Surface* Ventana::gScreenSurface = nullptr;

const int Ventana::SCREEN_WIDTH;
const int Ventana::SCREEN_HEIGHT;

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

int SDL_main(int argc, char *args[])
{
    Ventana ventana;

    if (!Ventana::init())
    {
        std::cerr << "Failed to initialize SDL." << std::endl;
        return 1;
    }

    if (!ventana.loadMedia())
    {
        std::cerr << "Failed to load media." << std::endl;
        ventana.close();
        return 1;
    }

    // Tu lógica de ventana SDL aquí...

    SDL_Event e;
    bool quit = false;

    while (!quit)
    {
        // Manejar eventos
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }

    Ventana::close();
    return 0;
}