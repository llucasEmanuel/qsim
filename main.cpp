#include "lib/Complex/complex.h"
#include "lib/Matrix/matrix.h"
#include "include/utils.h"

int main() {

    Complex cpx1(-2, 4);
    Complex cpx2(3, -4);

    PolarComplex pcpx1(2, -4);
    print(pcpx1 * PolarComplex(3, 2));

    print(pcpx1);

    Matrix<float> mat1(2, 2);
    Matrix<float> mat2(2, 2);
    mat1.set_element(1, 1, 0);
    mat2.set_element(1, 0, 0);
    print((mat1 + (mat2*2)).transpose());

    SquareMatrix<int> sm(4);

    print(sm);

    return 0;
}