#include "quantum_circuit.hpp"
#include <stdexcept>

QuantumCircuit::QuantumCircuit(int num_qubits) 
: curr_state(QuantumState(num_qubits)) {}

QuantumCircuit::QuantumCircuit(const QuantumState& initial_state) 
: curr_state(QuantumState(initial_state)) {}

QuantumCircuit::QuantumCircuit(const Eigen::VectorXcd& initial_state_vector) 
: curr_state(QuantumState(initial_state_vector, true)) {}

static QuantumGate generate_global_gate(const QuantumGate& gate, int num_qubits, const std::vector<std::size_t>& qubits) {
    QuantumGate applied_gates[num_qubits]; // initialized with I gate

    // naturally overwrites with the same gate in case of duplicate indexes
    for (std::size_t qubit : qubits) {
        applied_gates[qubit] = gate;
    }

    QuantumGate global_gate = applied_gates[0];
    // MSB = [0]
    for (int i = 1; i < num_qubits; i++) {
        global_gate = tensor_product(global_gate, applied_gates[i]);
    }
    return global_gate;
}

void QuantumCircuit::apply_gate(const QuantumGate& gate, const std::vector<std::size_t>& qubits) {
    for (std::size_t i : qubits) {
        if (i < 0 || i >= this->curr_state.get_num_qubits()) {
            throw std::out_of_range("Qubit " + std::to_string(i) + " out of range");
        }
    }

    QuantumGate global_gate = generate_global_gate(gate, this->curr_state.get_num_qubits(), qubits);

    this->curr_state = global_gate * this->curr_state;
    this->gate_list.push_back(global_gate);    
}


void QuantumCircuit::apply_gate(const std::string& basic_gate_name, const std::vector<std::size_t>& qubits) {
    this->apply_gate(QuantumGate(basic_gate_name), qubits);
}

void QuantumCircuit::apply_gate(const Eigen::MatrixXcd& gate_matrix, const std::vector<std::size_t>& qubits) {
    this->apply_gate(QuantumGate(gate_matrix), qubits);
}

QuantumState QuantumCircuit::get_current_state() const {
    return this->curr_state;
}

std::vector<QuantumGate> QuantumCircuit::get_gates_applied() const {
    return this->gate_list;
}


