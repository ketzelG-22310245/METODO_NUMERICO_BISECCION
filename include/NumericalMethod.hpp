#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <iomanip>
#include <cmath>

class NumericalMethod {
public:
    NumericalMethod();  // Constructor sin argumentos
    NumericalMethod(BisectionMethod& bisectionMethod);  // Constructor con BisectionMethod
    ~NumericalMethod();

<<<<<<< HEAD
    void run();
    double calculateFunction(double x);

private:
=======
    void run();   
    void renderBisectionResults(const BisectionMethod& bisectionMethod);
    double calculateFunction(double x);

private:
    //BisectionMethod& bisectionMethod;  // Referencia al objeto BisectionMethod
    BisectionMethod& bisectionMethod;  // Utilizamos una referencia en lugar de un puntero

    double windowWidth;  // Asegúrate de declarar windowWidth como una variable miembro
    double scaleFactor;  // Agrega scaleFactor como una variable miembro privada
>>>>>>> 938b4e6 (ventana abre)
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