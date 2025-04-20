#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>
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

    Matrix<T> transpose() const;

    Matrix<T> operator+(const Matrix<T>& mat) const;
    Matrix<T> operator-(const Matrix<T>& mat) const;
    Matrix<T> operator*(const Matrix<T>& mat) const;
    Matrix<T> operator*(const T& scalar) const;

protected:
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

    if (rows_ != mat.get_rows() || cols_ != mat.get_cols())
        throw std::invalid_argument("Dimensions does not match\n");
   
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            this->mat_[i][j] = mat.get_element(i, j);
        }
    }
}

template <typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> result(cols_, rows_);

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            result.set_element(mat_[i][j], j, i);
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& mat) const {
    if (rows_ != mat.get_rows() || cols_ != mat.get_cols())
        throw std::invalid_argument("Dimensions does not match\n");

    Matrix<T> result(rows_, cols_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            result.set_element(this->mat_[i][j] + mat.get_element(i, j), i, j);
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& mat) const {

    if (rows_ != mat.get_rows() || cols_ != mat.get_cols())
        throw std::invalid_argument("Dimensions does not match\n");

    Matrix<T> result(rows_, cols_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            result.set_element(this->mat_[i][j] - mat.get_element(i, j), i, j);
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& mat) const {
    
    if (cols_ != mat.get_rows())
        throw std::invalid_argument("Dimensions does not match\n");

    int mat_cols = mat.get_cols();
    Matrix<T> result(rows_, mat_cols);

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < mat_cols; j++) {
            T sum = T();
            for (int k = 0; k < cols_; k++) {
                sum += mat_[i][k] * mat.get_element(k, j);
            }
            result.set_element(sum, i, j);
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T& scalar) const {
    Matrix<T> result(rows_, cols_);

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            result.set_element(mat_[i][j] * scalar, i, j);
        }
    }

    return result;
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

template <typename T>
class SquareMatrix : public Matrix<T> {
public:
    SquareMatrix(const int size);
    
    int get_size() const;
};

template <typename T>
SquareMatrix<T>::SquareMatrix(const int size) : Matrix<T>(size, size) {};

template <typename T>
int SquareMatrix<T>::get_size() const {
    return this->get_rows();
}

#endif 