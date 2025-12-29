#ifndef QUANTUM_CIRCUIT_HPP
#define QUANTUM_CIRCUIT_HPP

#include "quantum_state.hpp"
#include "quantum_gate.hpp"

class QuantumCircuit {
private:
    QuantumState curr_state;
    std::vector<QuantumGate> gate_list;

public:
    QuantumCircuit(int num_qubits);
    QuantumCircuit(const QuantumState& initial_state);
    QuantumCircuit(const Eigen::VectorXcd& initial_state_vector);

    void apply_gate(const QuantumGate& gate, const std::vector<std::size_t>& qubits);
    void apply_gate(const std::string& basic_gate_name, const std::vector<std::size_t>& qubits);
    void apply_gate(const Eigen::MatrixXcd& gate_matrix, const std::vector<std::size_t>& qubits);

    QuantumState get_current_state() const;
    std::vector<QuantumGate> get_gates_applied() const;
};

#endif