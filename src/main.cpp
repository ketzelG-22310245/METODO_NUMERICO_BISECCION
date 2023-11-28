#include <iostream>
#include <iomanip>
#include <cmath>
#include <SDL.h>

#define PRECISION 5

using namespace std;

// Declare SDL_Window and SDL_Surface variables
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

double f(double x);
void imprimePuntos(double a, double b);

int main()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    // Create window
window = SDL_CreateWindow("Metodo biseccion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
if (window == NULL)
{
    cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
    return 1;
}

    // Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    // Fill the surface white
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    // Update the surface
    SDL_UpdateWindowSurface(window);

    // Hack to get window to stay up
    SDL_Event e;
    bool quit = false;
    while (quit == false)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
        }
    }

   cout << setprecision(PRECISION); // Establecemos la precisión
   
   double a, b, tolerancia;
   
   cout << "\nCalculo de las raices de una funcion aplicando el metodo de la biseccion" << endl;
   cout << "\nIngrese el intervalo inicial [a, b]" << endl;
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";
   cin >> b;
   
   imprimePuntos(a, b);
   
   cout << "\nEscoja el intervalo adecuado" << endl;
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";
   cin >> b;
   
   // [a, b]
   float xr; // raiz de la función
   float xr_antiguo = 0.0; // para almacenar el valor anterior de xr
   
   if (f(a) * f(b) > 0) {
      cout << "\nNo se puede aplicar el metodo de la biseccion\n";
      cout << "porque f(" << a << ") y f(" << b << ") tienen el mismo signo" << endl;
   } else {
      cout << "Tolerancia = ";
      cin >> tolerancia;
      cout << "\na\t\t\tb\t\t\tc\t\t\tf(c)\t\t\tEr\n" << endl;
      
      do {
         xr = (a + b) / 2.0;
         cout << a << "\t\t\t" << b << "\t\t\t" << xr << "\t\t\t";
         cout << f(xr) << "\t\t\t";

         // Calcular el error relativo
         float error_rel = (abs(xr - xr_antiguo) / abs(xr)) * 100.0;
         cout << error_rel << "%" << endl;

         // Vemos si cumple o no cumple
         if (abs(f(xr)) <= tolerancia) {
            cout << "\n\nPara una tolerancia " << tolerancia << " la raiz de f es " << xr << endl;
            break;
         } else {
            if (f(xr) * f(a) > 0) {
               a = xr;
            } else if (f(xr) * f(b) > 0) {
               b = xr;
            }
         }

         // Actualizar el valor anterior de xr
         xr_antiguo = xr;

      } while (1);
   }
   
   cin.get();
   cin.get();

   // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

   return 0;
}

double f(double x) 
{
   return pow(x,3) - 7;
}

#define INTERVALOS 6
void imprimePuntos(double a, double b)
{
   int puntos = INTERVALOS + 1;
   
   double ancho = (b - a) / INTERVALOS;
   
   cout << "\n";
   cout << "\tx\tf(x)\n" << endl;
   for (int i = 0; i < puntos; i++) {
      cout << "\t" << a << "\t" << f(a) << endl;
      a = a + ancho;
   }
}
