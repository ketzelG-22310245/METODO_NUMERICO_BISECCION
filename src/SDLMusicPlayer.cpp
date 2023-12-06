#include <SDLMusicPlayer.hpp>
#include <iostream>

SDLMusicPlayer::SDLMusicPlayer() : music(nullptr)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cerr << "Error initializing SDL_mixer: " << Mix_GetError() << std::endl;
    }
}

SDLMusicPlayer::~SDLMusicPlayer()
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}

bool SDLMusicPlayer::loadMusic(const char *musicPath)
{
    music = Mix_LoadMUS(musicPath);
    if (music == nullptr)
    {
        std::cerr << "Error loading music: " << Mix_GetError() << std::endl;
        return false;
    }

    return true;
}

void SDLMusicPlayer::play()
{
    if (Mix_PlayingMusic() == 0)
    {
        Mix_PlayMusic(music, -1);
    }
}

void SDLMusicPlayer::pause()
{
    if (Mix_PlayingMusic() == 1)
    {
        Mix_PauseMusic();
    }
}

void SDLMusicPlayer::resume()
{
    if (Mix_PausedMusic() == 1)
    {
        Mix_ResumeMusic();
    }
}

void SDLMusicPlayer::stop()
{
    Mix_HaltMusic();
}