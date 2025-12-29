#include "quantum_gate.hpp"
#include <complex>
#include <cmath>
#include <stdexcept>
#include <cctype>
#include <unsupported/Eigen/KroneckerProduct>

namespace Gates {
    const Eigen::Matrix2cd I = Eigen::Matrix2cd::Identity();

    const Eigen::Matrix2cd X = (Eigen::Matrix2cd() << 0, 1, 
                                                      1, 0).finished();

    const Eigen::Matrix2cd Y = (Eigen::Matrix2cd() << 0, std::complex<double>(0, -1), 
                                                      std::complex<double>(0, 1), 0).finished();

    const Eigen::Matrix2cd Z = (Eigen::Matrix2cd() << 1, 0, 
                                                      0, -1).finished();

    const Eigen::Matrix2cd H = (Eigen::Matrix2cd() << 1.0,  1.0, 
                                                      1.0, -1.0).finished() * (1.0 / std::sqrt(2.0));   
                                                      
    const Eigen::Matrix4cd CNOT = (Eigen::Matrix4cd() << 1, 0, 0, 0,
                                                         0, 1, 0, 0,
                                                         0, 0, 0, 1,
                                                         0, 0, 1, 0).finished();

    const std::map<std::string, Eigen::MatrixXcd> basic_gates = {{"I", Gates::I},
                                                                 {"X", Gates::X},
                                                                 {"Y", Gates::Y},
                                                                 {"Z", Gates::Z},
                                                                 {"H", Gates::H},
                                                                 {"CNOT", Gates::CNOT},
                                                                };
}

QuantumGate::QuantumGate() {
    this->matrix = Gates::I;
}

QuantumGate::QuantumGate(std::string gate_name) {
    std::string original_gate_name = gate_name;
    // & guarantees the modification of the real char instead of its copy
    for (char& c : gate_name) {
        c = std::toupper(c);
    }

    auto it = Gates::basic_gates.find(gate_name);
    if (it == Gates::basic_gates.end()) {
        throw std::invalid_argument("No gate named " + original_gate_name + " found. Basic gates supported: I, X, Y, Z, H, CNOT.");
    }
    
    this->matrix = it->second;
}

QuantumGate::QuantumGate(Eigen::MatrixXcd matrix) {
    if (!matrix.isUnitary()) {
        throw std::invalid_argument("Received matrix has to be unitary");
    }

    this->matrix = matrix;
}

Eigen::MatrixXcd QuantumGate::get_matrix() const {
    return this->matrix;
}

QuantumGate QuantumGate::get_inverse() const {
    return QuantumGate(this->matrix.adjoint());
}

QuantumState QuantumGate::operator*(const QuantumState& state) const {
    if (this->get_matrix().cols() != state.get_state_vector().rows()) {
        throw std::invalid_argument("Incompatible dimensions between gate and state: ");
    }
    return QuantumState(static_cast<Eigen::VectorXcd>(this->get_matrix() * state.get_state_vector()), false);
}

QuantumGate QuantumGate::operator*(const QuantumGate& gate) const {
    if (this->get_matrix().cols() != gate.get_matrix().rows()) {
        throw std::invalid_argument("Incompatible dimensions between gates: ");
    }
    return QuantumGate(static_cast<Eigen::MatrixXcd>(this->get_matrix() * gate.get_matrix()));
}

QuantumGate tensor_product(const QuantumGate& gate1, const QuantumGate& gate2) {
    return QuantumGate(Eigen::kroneckerProduct(gate1.get_matrix(), gate2.get_matrix()).eval());
}

QuantumGate tensor_product(const QuantumGate& gate, int n) {
    QuantumGate result = gate;
    for (int i = 1; i < n; i++) {
        result = tensor_product(result, gate);
    }
    return result;
}