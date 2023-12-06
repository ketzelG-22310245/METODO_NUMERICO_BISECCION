#pragma once

#include <SDL2/SDL_mixer.h>

class SDLMusicPlayer
{
public:
    SDLMusicPlayer();
    ~SDLMusicPlayer();

    bool loadMusic(const char *musicPath);
    void play();
    void pause();
    void resume();
    void stop();

private:
    Mix_Music *music;
};