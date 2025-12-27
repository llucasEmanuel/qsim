#include <iostream>
#include "../quantum_state.hpp"
#include "../quantum_gate.hpp"

using namespace Eigen;

int main() {
    QuantumState s(2);

    Matrix4cd HI = tensor_product(Gates::H, Gates::I);

    Eigen::VectorXcd state_vec = HI * s.get_state_vector();
    
    state_vec = Gates::CNOT * state_vec;

    std::cout << state_vec << '\n';

    return 0;
}