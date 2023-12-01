#include <iostream>
#include <iomanip>
#include <cmath>
#include <Ventana.hpp>

#define PRECISION 3

using namespace std;

/*int otraCosa(double f(double x))
{

    Ventana ventana;

    if (!Ventana::init())
    {
        cout << "Error al inicializar la ventana." << endl;
        return 1;
    }

    if (!Ventana::loadMedia())
    {
        cout << "Error al cargar los medios." << endl;
        Ventana::close();
        return 1;
    }



        cin.get();
        cin.get();

        Ventana::close();
        return 0;
    }
}
*/

double f(double x)
{
}

int main(int argc, char **argv)
{
    Ventana ventana;

    if (!Ventana::init())
    {
        std::cerr << "Failed to initialize SDL." << std::endl;
        return 1;
    }

    if (!ventana.loadMedia())
    {
        std::cerr << "Failed to load media." << std::endl;
        ventana.close();
        return 1;
    }

    if (!ventana.loadMedia())
    {
        cout << setprecision(PRECISION); // Establecemos la precisión

        double a, b, tolerancia;

        cout << "\nCalculo de las raíces de una función aplicando el método de la bisección" << endl;
        cout << "\nIngrese el intervalo inicial [a, b]" << endl;
        cout << "\na = ";
        cin >> a;

        cout << "b = ";
        cin >> b;

        Ventana::imprimePuntos(a, b);

        cout << "\nEscoja el intervalo adecuado" << endl;
        cout << "\na = ";
        cin >> a;

        cout << "b = ";
        cin >> b;

        // [a, b]
        float xr;               // raíz de la función
        float xr_antiguo = 0.0; // para almacenar el valor anterior de xr

        // const double tolerancia = 1e-5;  // Ajusta la tolerancia según tus necesidades
        const int MAX_ITERATIONS = 100; // Ajusta el límite máximo de iteraciones según tus necesidades

        if (f(a) * f(b) > 0)
        {
            cout << "\nNo se puede aplicar el método de la bisección\n";
            cout << "porque f(" << a << ") y f(" << b << ") tienen el mismo signo" << endl;
        }
        else
        {
            cout << "Tolerancia = " << tolerancia << endl;
            cout << "\na\t\t\tb\t\t\tc\t\t\tf(c)\t\t\tEr\n"
                 << fixed << setprecision(PRECISION) << endl;

            int iterationCount = 0; // Contador para realizar un seguimiento de las iteraciones

            do
            {
                xr = (a + b) / 2.0;
                cout << a << "\t\t\t" << b << "\t\t\t" << xr << "\t\t\t";
                cout << f(xr) << "\t\t\t";

                float error_rel = (abs(xr - xr_antiguo) / abs(xr)) * 100.0;
                cout << fixed << setprecision(PRECISION) << error_rel << "%" << endl;

                if (abs(f(xr)) <= tolerancia || iterationCount >= MAX_ITERATIONS)
                {
                    if (abs(f(xr)) <= tolerancia)
                    {
                        cout << "\n\nPara una tolerancia " << tolerancia << " la raíz de f es " << xr << endl;
                    }
                    else
                    {
                        cout << "\n\nSe alcanzó el número máximo de iteraciones (" << MAX_ITERATIONS << ")." << endl;
                    }
                    break;
                }
                else
                {
                    if (f(xr) * f(a) > 0)
                    {
                        a = xr;
                    }
                    else if (f(xr) * f(b) > 0)
                    {
                        b = xr;
                    }
                }

                xr_antiguo = xr;
                iterationCount++;

            } while (true);
        }

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

        cin.get();
        cin.get();

        Ventana::close();
        return 0;
    }
}
