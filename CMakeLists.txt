cmake_minimum_required(VERSION 3.14)
project(qsim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Eigen installation
include(FetchContent)
FetchContent_Declare(
  eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG 3.4.0
)
FetchContent_MakeAvailable(eigen)

# OpenMP configuration for Eigen parallelism
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message(STATUS "OpenMP found! Paralelism activated.")
else()
    message(WARNING "OpenMP not found. Running in serial mode.")
endif()

add_library(QuantumLib src/base/quantum_state.cpp)

target_include_directories(QuantumLib PUBLIC include)

target_link_libraries(QuantumLib PUBLIC Eigen3::Eigen)

target_compile_options(QuantumLib PUBLIC 
    $<$<CXX_COMPILER_ID:GNU>:-O3 -march=native -fopenmp>
    $<$<CXX_COMPILER_ID:Clang>:-O3 -march=native -fopenmp>
)

if(OpenMP_CXX_FOUND)
    target_link_libraries(QuantumLib PUBLIC OpenMP::OpenMP_CXX)
endif()

add_executable(qsim_exec src/base/example/tensor_product.cpp)

target_link_libraries(qsim_exec PRIVATE QuantumLib)