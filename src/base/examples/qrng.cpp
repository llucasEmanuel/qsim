#include <iostream>
#include "../quantum_circuit.hpp"

int main() {

    QuantumCircuit circ(4);

    circ.apply_gate("H", {0, 1, 2, 3});

    std::cout << circ.get_current_state().get_state_vector() << "\n\n";
    
    for (auto g : circ.get_gates_applied()) {
        std::cout << g.get_matrix() << '\n';
    }

    return 0;
}