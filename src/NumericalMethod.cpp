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
    windowWidth = 800;  // O el valor que corresponda

    // Crear un objeto BisectionMethod
    BisectionMethod bisectionMethod;

    // Llamar a renderBisectionResults con el objeto creado
    renderBisectionResults(bisectionMethod);
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

        

        renderBisectionResults(bisectionMethod);

        SDL_Delay(16); // Ajusta según la frecuencia de actualización deseada
    }

    SDL_RenderPresent(renderer); // Asegúrate de presentar el renderer antes de salir
    SDL_Delay(5000);             // Espera 5 segundos antes de cerrar la ventana
}

void NumericalMethod::renderBisectionResults(const BisectionMethod &bisectionMethod)
{
    // Limpiar el renderer
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Dibujar puntos o líneas según los resultados del Método de Bisección
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Ejemplo de dibujo de puntos basados en resultados de bisección
    for (int i = 0; i < 800; i += 10)
    {
        double x = i;
        // Asegúrate de que x esté dentro de los límites deseados
        if (x >= 0 && x <= windowWidth)
        {
            double y = calculateFunction(x);
            SDL_RenderDrawPoint(renderer, static_cast<int>(x), static_cast<int>(y));
        }
    }

    for (int i = 0; i < 800; i += 10)
    {
        double x = i;
        if (x >= 0 && x <= windowWidth)
        {
            double y = calculateFunction(x);
            // Ajusta la escala de y según sea necesario
            y = y * scaleFactor;
            SDL_RenderDrawPoint(renderer, static_cast<int>(x), static_cast<int>(y));
        }
    }

    for (int i = 0; i < 800; i += 10)
    {
        double x = i;
        if (x >= 0 && x <= windowWidth)
        {
            double y = calculateFunction(x);
            std::cout << "x: " << x << ", y: " << y << std::endl;
            SDL_RenderDrawPoint(renderer, static_cast<int>(x), static_cast<int>(y));
        }
    }

    // Presentar el renderer
    SDL_RenderPresent(renderer);
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