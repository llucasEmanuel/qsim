#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix {
public:
    Matrix(const int rows, const int cols);
    //Matrix(const T **mat, const int rows, const int cols);
    ~Matrix();

    void set_element(T value, int i, int j);
    T get_element(int i, int j) const;

    int get_rows() const;
    int get_cols() const;

    Matrix operator+(const Matrix& mat) const;
    Matrix operator-(const Matrix& mat) const;
    Matrix operator*(const Matrix& mat) const;
    Matrix operator*(const T& scalar) const;
    Matrix operator=(const Matrix& mat) const;

private:
    T **mat_;
    const int rows_;
    const int cols_; 
};

template <typename T>
void print(const Matrix<T>& mat);

#include <iostream>

template <typename T>
Matrix<T>::Matrix(const int rows, const int cols) : rows_(rows), cols_(cols) {
    this->mat_ = new T*[this->rows_];
    for (int i = 0; i < this->rows_; i++) {
        this->mat_[i] = new T[this->cols_];
        for (int j = 0; j < this->cols_; j++) {
            this->mat_[i][j] = T();
        }
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < this->rows_; i++) {
        delete[] this->mat_[i];
    }
    delete[] this->mat_;
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
void print(const Matrix<T>& mat) {
    for (int i = 0; i < mat.get_rows(); i++) {
        for (int j = 0; j < mat.get_cols(); j++) {
            print(mat.get_element(i, j));
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}

#endif /* MATRIX_H */