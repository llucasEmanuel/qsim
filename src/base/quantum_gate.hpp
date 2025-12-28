#ifndef QUANTUM_GATE_HPP
#define QUANTUM_GATE_HPP

#include <Eigen/Dense>
#include "quantum_state.hpp"
#include <map>

namespace Gates {
    extern const Eigen::Matrix2cd I;
    extern const Eigen::Matrix2cd X;
    extern const Eigen::Matrix2cd Y;
    extern const Eigen::Matrix2cd Z;
    extern const Eigen::Matrix2cd H;
    extern const Eigen::Matrix4cd CNOT;

    extern const std::map<std::string, Eigen::MatrixXcd> basic_gates;
}

// TODO:: add operator for H*s

class QuantumGate {
private:
    Eigen::MatrixXcd matrix;

public:
    QuantumGate(std::string gate_name);
    QuantumGate(Eigen::MatrixXcd matrix);

    Eigen::MatrixXcd get_matrix() const;
    QuantumGate get_inverse() const;

    QuantumState operator*(const QuantumState& state);
    QuantumGate operator*(const QuantumGate& gate);
};

QuantumGate tensor_product(const QuantumGate& gate1, const QuantumGate& gate2);
QuantumGate tensor_product(const QuantumGate& gate, int n); // Auto tensor product

#endif