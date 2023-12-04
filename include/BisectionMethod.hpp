#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>

class BisectionMethod {
public:
    BisectionMethod();
    ~BisectionMethod();

    void calculateRoots();
    static const int INTERVALOS = 6;

private:
    double a, b, tolerance;

    void getInput();
    void printPoints();
    double function(double x);
};