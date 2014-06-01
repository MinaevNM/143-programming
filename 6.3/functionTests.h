#pragma once
#include <list>

#include <iostream>
#include <cmath>

#include "matrix.h"

using namespace std;

double const ZERO = 1e-5;

Matrix<double> solveMatrix(Matrix<double> matrix);
double *calculate(const Matrix<double> &matrix);
double *findFreeVar(const Matrix<double> &matrix);
void trinagular(Matrix<double> &matrix);

//главный тест
void compareTest(list< Matrix<double> > &input, list<Matrix<double> > &output);

//тесты для функций
void testTrinagular(list< Matrix<double> > listMatrix);
void testCalculate(list< Matrix<double> > listMatrix);
void testFindFreeVar(list< Matrix<double> > listMatrix);
