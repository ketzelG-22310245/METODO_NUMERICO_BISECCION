#include <iostream>
#include <iomanip>
#include <cmath>
#include "C:\Users\Ketzel\Desktop\METODO_NUMERICO_BISECCION\include\Biseccion.hpp"

using namespace std;

double f(double x) {
    return x - 4*sin(x);
}

#define INTERVALOS 6
void Biseccion::imprimePuntos(double a, double b) {
    int puntos = INTERVALOS + 1;

    double ancho = (b - a) / INTERVALOS;

    cout << "\n";
    cout << "\tx\tf(x)\n"
         << endl;
    for (int i = 0; i < puntos; i++) {
        cout << "\t" << a << "\t" << f(a) << endl;
        a = a + ancho;
    }
}