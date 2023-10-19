#include "Array3D.h"


template <typename T>
Array3D<T>::Array3D(int dim0, int dim1, int dim2) {
    this->dim0 = dim0;
    this->dim1 = dim1;
    this->dim2 = dim2;
    this->arr.resize(dim0 * dim1 * dim2);
}

template <typename T>
T& Array3D<T>::operator()(int i, int j, int k) {
    return arr[i * dim1 * dim2 + j * dim2 + k];
}

template <typename T>
std::vector<T> Array3D<T>::GetValues0(int i) {
    std::vector<T> result(dim1 * dim2);
    for (int j = 0; j < dim1; j++) {
        for (int k = 0; k < dim2; ++k) {
            result[j * dim2 + k] = this->arr[i * dim1 * dim2 + j * dim2 + k];
        }
    }
    return result;
}

template <typename T>
std::vector<T> Array3D<T>::GetValues1(int j) {
    std::vector<T> result(dim0 * dim2);
    for (int i = 0; i < dim0; ++i) {
        for (int k = 0; k < dim2; ++k) {
            result[i * dim2 + k] = this->arr[i * dim1 * dim2 + j * dim2 + k];
        }
    }
    return result;
}

template <typename T>
std::vector<T> Array3D<T>::GetValues2(int k) {
    std::vector<T> result(dim0 * dim1);
    for (int i = 0; i < dim0; i++) {
        for (int j = 0; j < dim1; j++) {
            result[i * dim1 + j] = this->arr[i * dim1 * dim2 + j * dim2 + k];
        }
    }
    return result;
}

template <typename T>
std::vector<T> Array3D<T>::GetValues01(int i, int j) {
    std::vector<T> result(dim2);
    for (int k = 0; k < dim2; k++) {
        result[k] = this->arr[i * dim1 * dim2 + j * dim2 + k];
    }
    return result;
}

template <typename T>
std::vector<T> Array3D<T>::GetValues02(int i, int k) {
    std::vector<T> result(dim1);
    for (int j = 0; j < dim1; j++) {
        result[j] = this->arr[i * dim1 * dim2 + j * dim2 + k];
    }
    return result;
}

template <typename T>
std::vector<T> Array3D<T>::GetValues12(int j, int k) {
    std::vector<T> result(dim0);
    for (int i = 0; i < dim0; i++) {
        result[i] = this->arr[i * dim1 * dim2 + j * dim2 + k];
    }
    return result;
}

template <typename T>
void Array3D<T>::SetValues0(int i, std::vector<std::vector<T>> arr) {
    for (int j = 0; j < this->dim1; j++) {
        for (int k = 0; k < this->dim2; k++) {
            this->arr[i * this->dim1 * this->dim2 + j * this->dim2 + k] = arr[j][k];
        }
    }
}


template <typename T>
void Array3D<T>::SetValues1(int j, std::vector<std::vector<T>> arr) {
    for (int i = 0; i < this->dim0; i++) {
        for (int k = 0; k < this->dim2; k++) {
            this->arr[i * this->dim1 * this->dim2 + j * this->dim2 + k] = arr[j][k];
        }
    }
}

template <typename T>
void Array3D<T>::SetValues2(int k, std::vector<std::vector<T>> arr) {
    for (int i = 0; i < this->dim0; i++) {
        for (int j = 0; j < this->dim1; j++) {
            this->arr[i * this->dim1 * this->dim2 + j * this->dim2 + k] = arr[j][k];
        }
    }
}

template <typename T>
void Array3D<T>::SetValues01(int i, int j, std::vector<T> arr) {
    for (int k = 0; k < this->dim2; k++) {
        this->arr[i * this->dim1 * this->dim2 + j * this->dim2 + k] = arr[k];
    }
}

template <typename T>
void Array3D<T>::SetValues02(int i, int k, std::vector<T> arr) {
    for (int j = 0; j < this->dim1; j++) {
        this->arr[i * this->dim1 * this->dim2 + j * this->dim2 + k] = arr[j];
    }
}

template <typename T>
void Array3D<T>::SetValues12(int j, int k, std::vector<T> arr) {
    for (int i = 0; i < this->dim0; i++) {
        this->arr[i * this->dim1 * this->dim2 + j * this->dim2 + k] = arr[i];
    }
}

template <typename T>
int Array3D<T>::GetSize() {
    return this->arr.size();
}

template <typename T>
void Array3D<T>::FillNum(T num) {
    for (int i = 0; i < this->dim0; i++) {
        for (int j = 0; j < this->dim1; j++) {
            for (int k = 0; k < this->dim2; k++) {
                this->arr[i * this->dim1 * this->dim2 + j * this->dim2 + k] = num;
            }
        }
    }
}

template <typename T>
void Array3D<T>::FillZeros() {
    this->FillNum(0);
}

template <typename T>
void Array3D<T>::FillOnes() {
    this->FillNum(1);
}