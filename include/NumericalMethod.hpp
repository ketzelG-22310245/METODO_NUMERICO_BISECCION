#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <iomanip>
#include <cmath>

#include "BisectionMethod.hpp"

class NumericalMethod {
public:
    NumericalMethod();
    ~NumericalMethod();

    void run();
    void renderBisectionResults(const BisectionMethod& bisectionMethod);
    double calculateFunction(double x);

private:
    double windowWidth;  // Asegúrate de declarar windowWidth como una variable miembro
    double scaleFactor;  // Agrega scaleFactor como una variable miembro privada
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

    void initializeSDL();
    void createWindow();
    void createRenderer();
    void processEvents();
    void render();
    
    void cleanup();
};