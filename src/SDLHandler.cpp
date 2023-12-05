#include <SDLHandler.hpp>
#include <iostream>

SDLHandler::SDLHandler() : gWindow(nullptr), gScreenSurface(nullptr), gXOut(nullptr), quit(false)
{
}

SDLHandler::~SDLHandler()
{
    close();
}

bool SDLHandler::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    gWindow = SDL_CreateWindow("Presentacion proyecto", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 439, 426, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr)
    {
        std::cerr << "Error al crear la ventana: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    gScreenSurface = SDL_GetWindowSurface(gWindow);
    return true;
}

bool SDLHandler::loadMedia(const char *imagePath)
{
    gXOut = SDL_LoadBMP(imagePath);
    if (gXOut == nullptr)
    {
        std::cerr << "Error loading image: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void SDLHandler::close()
{
    SDL_FreeSurface(gXOut);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

void SDLHandler::render()
{
    SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);
    SDL_UpdateWindowSurface(gWindow);
}

void SDLHandler::handleEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_x:
                quit = true;
                break;
            }
        }
    }
}

bool SDLHandler::shouldQuit() const
{
    return quit;
}