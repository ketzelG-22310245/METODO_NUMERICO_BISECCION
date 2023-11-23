#include <iostream>
#include <cmath>
#include <iomanip>
#include <muParser.h>

using namespace std;

double evaluateFunction(mu::Parser& parser, double x) {
    parser.DefineVar("x", &x);
    return parser.Eval();
}

double biseccion(mu::Parser& parser, double a, double b, int it) {
    double c, lim0, lim1, x;

    c = (a + b) / 2;
    x = a;
    lim0 = evaluateFunction(parser, x);
    x = b;
    lim1 = evaluateFunction(parser, x);

    cout << "A: " << a << "\t\t" << "B: " << b << "\t\t" << "C: " << c << endl;
    cout << "f(A): " << lim0 << "\t\t" << "f(B): " << lim1 << "\t\t" << "f(C): " << evaluateFunction(parser, c) << endl;

    if (lim0 * lim1 < 0) {
        x = c;
        lim1 = evaluateFunction(parser, x);
        cout << "f(C): " << lim1 << endl;

        while (lim0 * lim1 != 0 && it > 0) {
            if (lim0 * lim1 < 0) {
                b = c;
                c = (a + b) / 2;
                x = c;
                lim1 = evaluateFunction(parser, x);

                cout << "A: " << a << "\t" << "B: " << b << "\t" << "C: " << c << endl;
                cout << "f(A): " << evaluateFunction(parser, a) << "\t\t" << "f(B): " << evaluateFunction(parser, b) << "\t\t"
                     << "f(C): " << lim1 << endl;
            } else if (lim0 * lim1 > 0) {
                a = c;
                c = (a + b) / 2;
                x = c;
                lim1 = evaluateFunction(parser, x);

                cout << "A: " << a << "\t" << "B: " << b << "\t" << "C: " << c << endl;
                cout << "f(A): " << evaluateFunction(parser, a) << "\t\t" << "f(B): " << evaluateFunction(parser, b) << "\t\t"
                     << "f(C): " << lim1 << endl;
            }
            --it;
        }
    } else {
        cout << "La raíz no se encuentra en el intervalo." << endl;
    }
    return c;
}

int main() {
    double a, b;
    int it;
    string functionString;

    cout << "Ingrese la función (por ejemplo, x^2 - 4): ";
    getline(cin, functionString);

    mu::Parser parser;
    parser.SetExpr(functionString);

    cout << "Ingrese el valor de a: ";
    cin >> a;
    cout << "Ingrese el valor de b: ";
    cin >> b;
    cout << "Ingrese el número de iteraciones: ";
    cin >> it;

    cout << "A: " << a << "\t\t" << "B: " << b << "\t\t" << "C: ";
    double raiz = biseccion(parser, a, b, it);

    cout << setprecision(5) << "La raiz es: " << raiz << endl;

    return 0;
}