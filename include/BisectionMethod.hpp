#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>

class BisectionMethod {
public:
    BisectionMethod();
    ~BisectionMethod();

    void calculateRoots(double a, double b, double tolerancia);
    void getInput();
    void printPoints();
    double function(double x);
    
    static const int INTERVALOS = 6;
    double a, b, tolerance;

private:
    

};