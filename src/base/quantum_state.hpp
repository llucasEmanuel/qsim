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

    Eigen::RowVectorXcd adjoint() const;
    Eigen::MatrixXcd density_matrix() const;

    int get_num_qubits() const;
    const Eigen::VectorXcd& get_state_vector() const;
};

QuantumState tensor_product(const QuantumState& state1, const QuantumState& state2); 

#endif