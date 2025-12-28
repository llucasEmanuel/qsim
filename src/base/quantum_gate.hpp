#ifndef QUANTUM_GATE_HPP
#define QUANTUM_GATE_HPP

#include <Eigen/Dense>
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

    Eigen::MatrixXcd get_matrix();
    QuantumGate get_inverse();

};

#endif