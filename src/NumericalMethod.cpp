#include <NumericalMethod.hpp>
#include <BisectionMethod.hpp>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>

NumericalMethod::NumericalMethod()
{
    initializeSDL();
    createWindow();
    createRenderer();
    isRunning = true;
}

NumericalMethod::~NumericalMethod()
{
    cleanup();
}

void NumericalMethod::run()
{
    BisectionMethod bisectionMethod;

    while (isRunning)
    {
        processEvents();

        // Resto del código...

        render();
    }

    SDL_Delay(5000); // Espera 5 segundos antes de cerrar la ventana
}

double NumericalMethod::calculateFunction(double x)
{
    return x - 4 * sin(x);
}

void NumericalMethod::initializeSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void NumericalMethod::createWindow()
{
    window = SDL_CreateWindow("Ventana para Método Numérico", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "Error al crear la ventana: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }
}

void NumericalMethod::createRenderer()
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cout << "Error al crear el renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }
}

void NumericalMethod::processEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
    }
}

void NumericalMethod::render()
{
    SDL_RenderPresent(renderer); // Asegúrate de tener un renderer definido
}

void NumericalMethod::cleanup()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}