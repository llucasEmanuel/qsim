#include <iostream>
#include "../quantum_state.hpp"
#include "../quantum_gate.hpp"

int main() {
    QuantumState s(2);

    QuantumGate had("h");
    QuantumGate id("I");

    Eigen::MatrixXcd hi = tensor_product(had.get_matrix(), id.get_matrix());
    QuantumGate HI(hi);

    Eigen::VectorXcd state_vec = HI.get_matrix() * s.get_state_vector();
    
    QuantumGate cnot("CNOT");

    state_vec = cnot.get_matrix() * state_vec;

    std::cout << state_vec << "\n\n";

    QuantumGate HI_inv = HI.get_inverse();
    cnot = cnot.get_inverse();
    state_vec = HI_inv.get_matrix() * cnot.get_matrix() * state_vec;
    std::cout << state_vec << '\n';

    return 0;
}