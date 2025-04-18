#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
    Complex(double, double);

    void set_real(double);
    double get_real() const;

    void set_imaginary(double);
    double get_imaginary() const;

    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;

private:
    double real_;
    double imag_;
};

class PolarComplex : public Complex {
public:
    PolarComplex(double, double);
    
    double get_magnitude() const;
    double get_angle() const;

    PolarComplex operator*(const PolarComplex&) const;

private:
    double mag_;
    double ang_;
};

#endif /* COMPLEX_H */