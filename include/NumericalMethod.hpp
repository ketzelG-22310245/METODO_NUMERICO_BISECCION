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
    double calculateFunction(double x);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

    void initializeSDL();
    void createWindow();
    void createRenderer();
    void processEvents();
    void render();
    void renderBisectionResults(const BisectionMethod& bisectionMethod);
    void cleanup();
};