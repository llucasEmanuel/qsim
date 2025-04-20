#include "gates.h"

Gate::Gate(const SquareMatrix<Complex>& mat) {
    this->matrix_.copy_from(mat);
}