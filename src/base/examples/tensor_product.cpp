#include <iostream>
#include "../quantum_state.hpp"

int main() {
    QuantumState s1(2);
    QuantumState s2(2);

    std::cout << s1.get_state_vector() << "\n\n";
    std::cout << s2.get_state_vector() << '\n';

    QuantumState res = tensor_product(s1, s2);
    
    int n = res.get_num_qubits();
    std::cout << "Final number of qubits: " << n << '\n';
    
    std::cout << "Vector size: " << res.get_state_vector().size() << '\n';

    std::cout << res.get_state_vector() << '\n';

    return 0;
}