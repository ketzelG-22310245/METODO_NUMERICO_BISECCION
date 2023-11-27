#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Función que evalúa la expresión para un valor dado
double evaluarFuncion(const string& funcion, double x) {
    // Aquí podrías implementar tu propio parser o usar una biblioteca de análisis sintáctico
    // Para simplificar, este ejemplo asumirá que la función es de la forma ax^2 + bx + c
    // y utilizará la biblioteca cmath para evaluarla.

    // Supongamos que la función es de la forma ax^2 + bx + c
    double a = 1.0;
    double b = 0.0;
    double c = 0.0;

    // Evaluar la expresión
    double resultado = a * pow(x, 2) + b * x + c;

    return resultado;
}

int main() {
    // Solicitar al usuario que ingrese una función
    string userFunction;
    cout << "Ingrese una función matemática (por ejemplo, x^2 + 3*x - 5): ";
    getline(cin, userFunction);

    // Solicitar al usuario que ingrese los límites del rango y la cantidad de puntos
    double limiteInferior, limiteSuperior;
    int cantidadPuntos;

    cout << "Ingrese el límite inferior del rango: ";
    cin >> limiteInferior;

    cout << "Ingrese el límite superior del rango: ";
    cin >> limiteSuperior;

    cout << "Ingrese la cantidad de puntos para tabular la función: ";
    cin >> cantidadPuntos;

    try {
        // Calcular el paso entre cada punto
        double paso = (limiteSuperior - limiteInferior) / (cantidadPuntos - 1);

        // Tabular la función en el rango especificado
        cout << "Resultados de la función en el rango [" << limiteInferior << ", " << limiteSuperior << "]:" << endl;
        for (int i = 0; i < cantidadPuntos; ++i) {
            double x = limiteInferior + i * paso;
            double result = evaluarFuncion(userFunction, x);
            cout << "x=" << x << ", f(x)=" << result << endl;
        }
    } catch (...) {
        cout << "Error al tabular la función." << endl;
    }

    return 0;
}