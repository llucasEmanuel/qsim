#include <iostream>
#include "../quantum_state.hpp"
#include "../quantum_gate.hpp"

int main() {
    QuantumState s(2);

    QuantumGate had("h");
    QuantumGate id("I");

    QuantumGate hi = tensor_product(had, id);
    
    QuantumGate HI(hi);

    s = HI * s;
    
    QuantumGate cnot("CNOT");

    s = cnot * s;

    std::cout << s.get_state_vector() << "\n\n";

    QuantumGate HI_inv = HI.get_inverse();
    cnot = cnot.get_inverse();
    
    s = HI_inv * cnot * s;

    std::cout << s.get_state_vector() << '\n';

    return 0;
}