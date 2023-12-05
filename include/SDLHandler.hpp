#pragma once

#include <SDL2/SDL.h>

class SDLHandler
{
public:
    SDLHandler();
    ~SDLHandler();

    bool init();
    bool loadMedia(const char *imagePath);
    void close();
    void render();
    void handleEvents();
    bool shouldQuit() const;

private:
    SDL_Window *gWindow;
    SDL_Surface *gScreenSurface;
    SDL_Surface *gXOut;
    bool quit;
};