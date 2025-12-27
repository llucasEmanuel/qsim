#include "quantum_gate.hpp"
#include <complex>
#include <cmath>

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
}