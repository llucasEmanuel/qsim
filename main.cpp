#include "lib/Complex/complex.h"
#include "lib/Matrix/matrix.h"
#include "include/utils.h"
#include <memory> // Para std::unique_ptr

int main() {

    Complex cpx1(-2, 4);
    Complex cpx2(3, -4);

    PolarComplex pcpx1(2, -4);
    print(pcpx1 * PolarComplex(3, 2));

    print(pcpx1);

    Matrix<float> mat(3, 4);
    mat.set_element(3.14, 0, 2);
    print(mat);

    

    return 0;
}