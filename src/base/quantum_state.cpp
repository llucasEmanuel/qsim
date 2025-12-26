#include "quantum_state.hpp"
#include <unsupported/Eigen/KroneckerProduct>
#include <stdexcept>
#include <complex>
#include <cmath>
#include <iostream>

QuantumState::QuantumState(int n) {
    if (n <= 0) {
        throw std::invalid_argument("Number of qubits has to be greater than 0. Received: " + std::to_string(n));
    }

    this->num_qubits = n;
    long long dim = 1LL << n; // 2**n
    this->state_vector.resize(dim);

    this->state_vector.setZero();
    this->state_vector(0) = {1.0, 0.0}; // std::complex<double>(1, 0);
}

QuantumState::QuantumState(const Eigen::VectorXcd& state_vector, bool normalize) {
    long long rows = state_vector.rows();
    if ((rows == 0) || ((rows & (rows - 1)) != 0)) {
        throw std::invalid_argument("The size of the vector has to be a power of 2 greater than 0. Received: " + std::to_string(rows));
    }

    double num_qubits = std::log2(rows);
    this->num_qubits = num_qubits;
    this->state_vector = state_vector;

    if (normalize) this->state_vector.normalize();
}

QuantumState::~QuantumState() {
    std::cout << "Destroying " << num_qubits << " qubit state.\n";
}

int QuantumState::get_num_qubits() const {
    return this->num_qubits;
}
    
const Eigen::VectorXcd& QuantumState::get_state_vector() const {
    return this->state_vector;
}

QuantumState tensor_product(const QuantumState& state1, const QuantumState& state2) {
    Eigen::VectorXcd state_vector = Eigen::kroneckerProduct(state1.get_state_vector(), state2.get_state_vector()).eval();
    return QuantumState(state_vector, false);
} 
