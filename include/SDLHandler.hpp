#pragma once

#include <SDLMusicPlayer.hpp>
#include <SDL2/SDL.h>

class SDLHandler
{
public:
    SDLHandler();
    ~SDLHandler();

    bool init();
    bool loadMedia(const char *imagePath, const char *musicPath);
    void close();
    void render();
    void handleEvents();
    bool shouldQuit() const;

private:
    SDL_Window *gWindow;
    SDL_Surface *gScreenSurface;
    SDL_Surface *gXOut;
    SDLMusicPlayer musicPlayer; // New member
    Mix_Music *gMusic;
    bool quit;
};