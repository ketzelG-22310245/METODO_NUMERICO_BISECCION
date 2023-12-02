#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
class Biseccion
{
private:
    
public:
    Biseccion(/* args */) {}
    double f(double x);
    void imprimePuntos(double a, double b);
    ~Biseccion() {}
};

double Biseccion::f(double x) {
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