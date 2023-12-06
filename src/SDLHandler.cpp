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
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    gWindow = SDL_CreateWindow("Presentacion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 439, 426, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr)
    {
        std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }

    gScreenSurface = SDL_GetWindowSurface(gWindow);
    return true;
}

bool SDLHandler::loadMedia(const char *imagePath, const char *musicPath)
{
    gXOut = SDL_LoadBMP(imagePath);
    if (gXOut == nullptr)
    {
        std::cerr << "Error loading image: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!musicPlayer.loadMusic(musicPath))
    {
        return false;
    }

    std::cout << "Loading music from: " << musicPath << std::endl;
    gMusic = Mix_LoadMUS(musicPath);
    if (gMusic == nullptr)
    {
        std::cerr << "Error loading music: " << Mix_GetError() << std::endl;
        return false;
    }

    std::cout << "Music loaded successfully." << std::endl;
    Mix_VolumeMusic(MIX_MAX_VOLUME);

    std::cout << "Playing music..." << std::endl;
    Mix_PlayMusic(gMusic, -1);
    if (Mix_PlayingMusic() == 0)
    {
        std::cerr << "Error playing music: " << Mix_GetError() << std::endl;
    }
    else
    {
        std::cout << "Music is playing." << std::endl;
    }

    return true;
}

void SDLHandler::close()
{
    SDL_FreeSurface(gXOut);
    SDL_DestroyWindow(gWindow);
    Mix_FreeMusic(gMusic);
    SDL_Quit();
}

void SDLHandler::render()
{
    SDL_BlitSurface(gXOut, nullptr, gScreenSurface, nullptr);
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
            case SDLK_m:
                musicPlayer.play();
                break;
            case SDLK_p:
                musicPlayer.pause();
                break;
            case SDLK_r:
                musicPlayer.resume();
                break;
            case SDLK_s:
                musicPlayer.stop();
                break;
            }
        }
    }
}

bool SDLHandler::shouldQuit() const
{
    return quit;
}