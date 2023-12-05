#include <iostream>
#include <cstdlib>
#include <BisectionMethod.hpp>
#include <SDLHandler.hpp>
#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char** argv) {
    SDLHandler sdlHandler;
    BisectionMethod bisectionMethod;

    if (!sdlHandler.init() || !sdlHandler.loadMedia("assets/images/Presentacion-progra.bmp")) {
        std::cerr << "Error al inicializar SDL o cargar medios." << std::endl;
        return 1;
    }

    while (!sdlHandler.shouldQuit()) {
        sdlHandler.handleEvents();
        sdlHandler.render();
    }

    sdlHandler.close();

    return 0;
}

