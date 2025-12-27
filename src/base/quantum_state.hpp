#ifndef STATE_VECTOR_HPP
#define STATE_VECTOR_HPP

#include <Eigen/Dense>

class QuantumState {
private:
    int num_qubits;
    Eigen::VectorXcd state_vector;

public:
    QuantumState(int n);
    QuantumState(const Eigen::VectorXcd& state_vector, bool normalize);
    ~QuantumState();

    int get_num_qubits() const;
    const Eigen::VectorXcd& get_state_vector() const;
};

QuantumState tensor_product(const QuantumState& state1, const QuantumState& state2); 

const Eigen::MatrixXcd tensor_product(const Eigen::MatrixXcd& gate1, const Eigen::MatrixXcd& gate2);

const Eigen::MatrixXcd tensor_product(const Eigen::MatrixXcd& gate, int n); // Auto tensor product

#endif