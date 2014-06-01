#pragma once
#include <iostream>
#include <cmath>
#include "fraq.h"

using namespace std;

//погрешность при сравнении матриц
double const FAULT = 0.05;

template <class T>
class Matrix
{
public:
    Matrix(T **newMatrix, int newHeight, int newWidth);
    ~Matrix();
    void print() const;
    int getWidth() const;
    int getHeight() const;

    Matrix(const Matrix<T> &anything);
    Matrix<T> &operator =(const Matrix<T> &anything);

    T *&operator [](int index) const;

    //опереаторы приближенного сравнения матриц
    template <class U>
    friend bool operator ==(const Matrix<U> &first, const Matrix<U> &second);
    template <class U>
    friend bool operator !=(const Matrix<U> &first, const Matrix<U> &second);

private:
    int height;
    int width;
    T **matrix;

    void deleteMatrix();
    void copyingMatrix(T **matrix, int height, int width);
};

template <class T>
Matrix<T>::Matrix(T **newMatrix, int newHeight, int newWidth)
{
    copyingMatrix(newMatrix, newHeight, newWidth);
}

template <class T>
Matrix<T>::~Matrix()
{
    deleteMatrix();
}

template <class T>
void Matrix<T>::print() const
{
    for (int i = 0; i < height; ++i)
    {
        cout << endl;
        for (int j = 0; j < width; ++j)
            cout << matrix[i][j] << ' ';
    }
    cout << endl;
}

template <class T>
int Matrix<T>::getWidth() const
{
    return width;
}

template <class T>
int Matrix<T>::getHeight() const
{
    return height;
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &anything)
{
    copyingMatrix(anything.matrix, anything.height, anything.width);
}

template <class T>
Matrix<T> &Matrix<T>::operator =(const Matrix<T> &anything)
{
    if (&anything != this)
    {
        if (matrix) deleteMatrix();
        copyingMatrix(anything.matrix, anything.height, anything.width);
    }

    return *this;
}

template <class T>
T *&Matrix<T>::operator [](int index) const
{
    return matrix[index];
}

template <class T>
void Matrix<T>::deleteMatrix()
{
    for (int i = 0; i < height; ++i)
        delete []matrix[i];
    delete []matrix;
}

template <class T>
void Matrix<T>::copyingMatrix(T **newMatrix, int newHeight, int newWidth)
{
    height = newHeight;
    width = newWidth;
    matrix = (height * width)?
                new T* [height] : NULL;

    for (int i = 0; i < height; ++i)
    {
        matrix[i] = new T[width];
        for (int j = 0; j < width; ++j)
            matrix[i][j] = newMatrix[i][j];
    }
}

template <class T>
bool operator ==(const Matrix<T> &first, const Matrix<T> &second)
{
    if (first.height != second.height || first.width != second.width)
        return false;

    for (int i = 0; i < first.height; ++i)
        for (int j = 0; j < first.width; ++j)
            if (abs(first[i][j] - second[i][j]) > FAULT)
                return false;

    return true;
}

template <class T>
bool operator !=(const Matrix<T> &first, const Matrix<T> &second)
{
    return !(first == second);
}
