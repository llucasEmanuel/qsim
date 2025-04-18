#include "complex.h"
#include <cmath>

Complex::Complex(double real, double imag) : real_(real), imag_(imag) {}

void Complex::set_real(double real) {
    this->real_ = real;
}

double Complex::get_real() const {
    return this->real_;
} 

void Complex::set_imaginary(double imag) {
    this->imag_ = imag;
}

double Complex::get_imaginary() const {
    return this->imag_;
}

Complex Complex::operator+(const Complex& cpx) const {
    return Complex(this->real_ + cpx.get_real(), this->imag_ + cpx.get_imaginary());
}

Complex Complex::operator-(const Complex& cpx) const {
    return Complex(this->real_ - cpx.get_real(), this->imag_ - cpx.get_imaginary());
}


PolarComplex::PolarComplex(double magnitude, double angle)
    : Complex(magnitude * cos(angle), magnitude * sin(angle)), mag_(magnitude), ang_(angle) {}

double PolarComplex::get_angle() const {
    return this->ang_;
}

double PolarComplex::get_magnitude() const {
    return this->mag_;
}

PolarComplex PolarComplex::operator*(const PolarComplex& pcpx) const {
    return PolarComplex(this->mag_ * pcpx.get_magnitude(), this->ang_ + pcpx.get_angle());
}