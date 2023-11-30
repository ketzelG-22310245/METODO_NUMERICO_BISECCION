#include "C:\Users\Ketzel\Desktop\METODO_NUMERICO_BISECCION\include\Ventana.hpp"
#include "C:\Users\Ketzel\Desktop\METODO_NUMERICO_BISECCION\include\Biseccion.hpp"

bool init() {
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    else
    {
        // Create window
        Ventana::gWindow = SDL_CreateWindow("Metodo de biseccion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr)
        {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
            // Get window surface
            Ventana::gScreenSurface = SDL_GetWindowSurface(Ventana::gWindow);
        }
    }

    return success;
}

void close() {
    SDL_DestroyWindow(Ventana::gWindow);

    // Quit SDL
    SDL_Quit();
}

int SDL_main(int argc, char* args[]) {
    if (!Ventana::init()) {
        std::cerr << "Failed to initialize SDL." << std::endl;
        return 1;
    }

    if (!Ventana::loadMedia()) {
        std::cerr << "Failed to load media." << std::endl;
        Ventana::close();
        return 1;
    }

    // Tu lógica de ventana SDL aquí...

    // Ahora puedes llamar a funciones de bisección
    double a = 0.0, b = 2.0;
    imprimePuntos(a, b);

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