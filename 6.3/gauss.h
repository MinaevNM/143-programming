// ----------------------------------------------------------------------------
/*
File: gauss.cpp
Description: Решение СЛАУ методом Гаусса
Language: C++
Author: Анкаренко Сергей
Reviewer: Минаев Никита
Co-autors: Минаев Никита
(c) Copyright group 143 2014
*/
// ----------------------------------------------------------------------------

#pragma once
#include "functionTests.h"

enum marks{ nil, freeCoefMark };

//главные функции
Matrix<double> solveMatrix(Matrix<double> matrix);
void trinagular(Matrix<double> &matrix);
double *findFreeVar(const Matrix<double> &matrix);
double *calculate(const Matrix<double> &matrix);
double *findParticalSolution(Matrix<double> matrix, const double *freeVar);
Matrix<double> findBasis(const Matrix<double> &matrix, double *freeVar);

//служебные функции
void fill(double *line, int length, double fillElement);
double findRoot(const Matrix<double> &matrix, const double *roots, int line, int column);
void substructLines(double *first, double *second, int column, int width);
int getColBasis(const double *freeVar, int width);
void createNullLastColumn(Matrix<double> &matrix);
