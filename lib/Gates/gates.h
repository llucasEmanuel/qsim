#ifndef GATES_H
#define GATES_H

#include "../Matrix/matrix.h"
#include "../Complex/complex.h"

class Gate {
public:
    Gate(const SquareMatrix<Complex>& mat);

private:
    SquareMatrix<Complex> matrix_;
};

#endif 