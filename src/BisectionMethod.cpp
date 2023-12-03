#include <BisectionMethod.hpp>

#define PRECISION 2
#define INTERVALOS 6

BisectionMethod::BisectionMethod() {
    getInput();
}

BisectionMethod::~BisectionMethod() {
    // Destructor
}

void BisectionMethod::calculateRoots(double a, double b, double tolerancia) {
    double xr;               // raíz de la función
    double xr_antiguo = 0.0;  // para almacenar el valor anterior de xr

    const int MAX_ITERATIONS = 500; // Ajusta el límite máximo de iteraciones según tus necesidades

    if (function(this->a) * function(this->b) > 0) {
        std::cout << "\nNo se puede aplicar el método de la bisección\n";
        std::cout << "porque f(" << a << ") y f(" << b << ") tienen el mismo signo" << std::endl;
    } else {
        std::cout << "Tolerancia = " << tolerancia << std::endl;
        std::cout << "\na\t\t\tb\t\t\tc\t\t\tf(c)\t\t\tEr\n" << std::fixed << std::setprecision(PRECISION) << std::endl;

        int iterationCount = 0; // Contador para realizar un seguimiento de las iteraciones

        do {
            xr = (a + b) / 2.0;
            std::cout << a << "\t\t\t" << b << "\t\t\t" << xr << "\t\t\t";
            std::cout << function(xr) << "\t\t\t";

            double error_rel = (std::abs(xr - xr_antiguo) / std::abs(xr)) * 100.0;
            std::cout << std::fixed << std::setprecision(PRECISION) << error_rel << "%" << std::endl;

            if (std::abs(function(xr)) <= tolerancia || iterationCount >= MAX_ITERATIONS) {
                if (std::abs(function(xr)) <= tolerancia) {
                    std::cout << "\n\nPara una tolerancia " << tolerancia << " la raíz de f es " << xr << std::endl;
                } else {
                    std::cout << "\n\nSe alcanzó el número máximo de iteraciones (" << MAX_ITERATIONS << ")." << std::endl;
                }
                break;
            } else {
                if (function(xr) * function(this->a) > 0) {
                    a = xr;
                } else if (function(xr) * function(this->b) > 0) {
                    b = xr;
                }
            }

            xr_antiguo = xr;
            iterationCount++;

        } while (true);
    }
}

void BisectionMethod::getInput() {
    std::cout << "\nCalculo de las raíces de una función aplicando el método de la bisección" << std::endl;
    std::cout << "\nIngrese el intervalo inicial [a, b]" << std::endl;
    std::cout << "\na = ";
    std::cin >> a;

    std::cout << "b = ";
    std::cin >> b;

    printPoints();

    std::cout << "\nEscoja el intervalo adecuado" << std::endl;
    std::cout << "\na = ";
    std::cin >> a;

    std::cout << "b = ";
    std::cin >> b;

    tolerance = 1e-5; // Ajusta la tolerancia según tus necesidades
}

void BisectionMethod::printPoints() {
    int points = INTERVALOS + 1;
    double width = (b - a) / INTERVALOS;

    std::cout << "\n";
    std::cout << "\tx\tf(x)\n"
              << std::endl;
    for (int i = 0; i < points; i++) {
        std::cout << "\t" << a << "\t" << function(a) << std::endl;
        a = a + width;
    }
}

double BisectionMethod::function(double x) {
    return x - 4 * sin(x);
}