#include <BisectionMethod.hpp>

BisectionMethod::BisectionMethod() {
    getInput();
}

BisectionMethod::~BisectionMethod() {
    // Destructor
}

void BisectionMethod::calculateRoots() {
    // Implementa aquí el método de la bisección
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