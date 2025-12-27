#ifndef QUANTUM_GATE_HPP
#define QUANTUM_GATE_HPP

#include <Eigen/Dense>

namespace Gates {
    extern const Eigen::Matrix2cd I;
    extern const Eigen::Matrix2cd X;
    extern const Eigen::Matrix2cd Y;
    extern const Eigen::Matrix2cd Z;
    extern const Eigen::Matrix2cd H;
    extern const Eigen::Matrix4cd CNOT;
}

class QuantumGate {
private:

public:

};

#endif