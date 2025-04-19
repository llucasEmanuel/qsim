#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

template <typename T>
class Matrix {
public:
    Matrix(const int rows, const int cols);

    void set_element(T value, int i, int j);
    T get_element(int i, int j) const;

    int get_rows() const;
    int get_cols() const;

    void copy_from(const Matrix& mat);

    Matrix<T> operator+(const Matrix& mat) const;
    Matrix<T> operator-(const Matrix& mat) const;
    Matrix<T> operator*(const Matrix& mat) const;
    Matrix<T> operator*(const T& scalar) const;

private:
    std::vector<std::vector<T>> mat_;
    const int rows_;
    const int cols_; 
};

template <typename T>
void print(const Matrix<T>& mat);

template <typename T>
Matrix<T>::Matrix(const int rows, const int cols) : 
    rows_(rows), cols_(cols), mat_(std::vector(rows, std::vector(cols, T()))) {}

template <typename T>
void Matrix<T>::set_element(T value, int i, int j) {
    this->mat_[i][j] = value;
}

template <typename T>
T Matrix<T>::get_element(int i, int j) const {
    return this->mat_[i][j];
}

template <typename T>
int Matrix<T>::get_rows() const {
    return this->rows_;
}

template <typename T>
int Matrix<T>::get_cols() const {
    return this->cols_;
}

template <typename T>
void Matrix<T>::copy_from(const Matrix<T>& mat) {
    if (this->cols_ != mat.get_cols() || this->rows_ != mat.get_rows()) return;

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            this->mat_[i][j] = mat.get_element(i, j);
        }
    }
}


template <typename T>
void print(const Matrix<T>& mat) {
    for (int i = 0; i < mat.get_rows(); i++) {
        for (int j = 0; j < mat.get_cols(); j++) {
            std::cout << mat.get_element(i, j) << ' ';
        }
        std::cout << '\n';
    }
}

#endif /* MATRIX_H */