#include "lib/Complex/complex.h"
#include "lib/Matrix/matrix.h"
#include "include/utils.h"

int main() {

    Complex cpx1(-2, 4);
    Complex cpx2(3, -4);
    print(cpx1 - cpx2);

    PolarComplex pcpx1(2, -4);
    print(pcpx1 * PolarComplex(3, 2));

    print(pcpx1);

    Matrix<Complex> mat(4, 5);
    print(mat);

    return 0;
}
