#include "utils.h"
#include <iostream>

void print(const Complex& cpx) {

    double real = cpx.get_real();
    double imag = cpx.get_imaginary();
    if (real != 0 || (real == 0 && imag == 0)) std::cout << real;

    if (imag > 0) {
        std::cout << '+';
    }
    if (imag != 0) std::cout << imag << 'i';
    std::cout << '\n';
    return;
}

void print(const PolarComplex& pcpx, bool algebric) {

    if (algebric) {
        print((Complex) pcpx);
        return;
    }

    double mag = pcpx.get_magnitude();
    double ang = pcpx.get_angle();

    std::cout << mag;

    if (mag != 0 && ang != 0) {
        std::cout << "*exp[i(" << ang << ")]\n";
    }
}