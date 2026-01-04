#include <iostream>
#include "../quantum_circuit.hpp"

int main() {

    QuantumCircuit circ(2);
    circ.apply_gate(Gates::X, {0, 1});

    std::cout << "p(|00>): " << circ.basis_state_probability(0) << "\n";
    std::cout << "p(|01>): " << circ.basis_state_probability(1) << "\n";
    std::cout << "p(|10>): " << circ.basis_state_probability(2) << "\n";
    std::cout << "p(|11>): " << circ.basis_state_probability(3) << "\n";
    
    return 0;
}