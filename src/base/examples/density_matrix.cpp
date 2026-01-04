#include <iostream>
#include "../quantum_circuit.hpp"

int main() {

    QuantumCircuit circ(2);
    circ.apply_gate("H", {0, 1});

    std::cout << circ.get_current_state().density_matrix() << "\n";
    
    return 0;
}