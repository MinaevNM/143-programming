#include <cmath>
#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

#define eps 1e-5 

matrix::matrix( int _n, int _m ) : n(_n), m(_m)
{
    // TODO: все переменные должны инициализироваться при создании,
    // в том числе и массивы
	// DONE
    a = new double *[n];
    for (int i = 0; i < n; i++)
        a[i] = new double[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = 0;
}

matrix::matrix( char * fileName )
{
    FILE *f = fopen(fileName, "rt");

    if (f == NULL)
        return;
    int _n, _m;
    fscanf(f, "%i %i", &_n, &_m);

    n = _n;
    m = _m;

    a = new double *[n];
    for (int i = 0; i < n; i++)
        a[i] = new double[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(f, "%lf", &a[i][j]);

    fclose(f);
}

void matrix::subst( int s1, int s2, double c )
{
    // TODO: [A] 1e-5 "Магические переменные" - зло. Следует дать ей имя.
    // DONE
    // TODO: [A] Нужно добавить проверку на положительность s1 и s2.
	// DONE
    if (s1 < 0 || s2 < 0 || s1 >= n || s2 >= n || fabs(c) < eps)
        return;
    for (int i = 0; i < m; i++)
        a[s2][i] -= a[s1][i] * c;
}

void matrix::mult( int s, double c )
{
    if (fabs(c) < eps)
        return;
    for (int i = 0; i < m; i++)
        a[s][i] *= c;
}

void matrix::Swap( int s1, int s2 )
{
    swap(a[s1], a[s2]);
}

void matrix::swapBiggest( int from, int column )
{
    int max = from;

    for (int i = from + 1; i < n; i++)
        if (fabs(a[i][column]) > fabs(a[max][column]))
            max = i;
    Swap(from, max);
}

// TODO: [A] сделать нерекурсивной
void matrix::substFromAll( int num, int from, int column )
{
    if (fabs(a[num][column]) < eps)
    {
        substFromAll(num, from, column + 1);
        return;
    }

    for (int i = from; i < n; i++)
    {
        matrix::subst(num, i, a[i][column] / a[num][column]);
	}
}

void matrix::Gauss()
{
    for (int i = 0; i < n; i++)
    {
        swapBiggest(i, i);
        substFromAll(i, i + 1, i);
    }
}

// TODO: [A] функции findBasis и checkResult содержат много одинакового
// кода -> они слишком большие. Нужно разбить на функции попроще.
void matrix::findBasis( int freeVar, FILE * _f )
{
    for (int l = 0; l < freeVar; l++)
    {
        double * basis = new double[m - 1];
        // TODO: [A] Непонятно, что означают переменные t и f, m. Нужно дать им осознанные имена.
        int t = m - 2;
        int f = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int countZero = 0;
            int countNonZero = 0;

            for (int j = 0; j < m - 1; j++)
            {
                if (fabs(a[i][j]) < eps)
                    countZero++;
                else
                    break;
            }
            countNonZero = m - 1 - countZero;

            if (countNonZero == 0)
                continue;

            int freeVariables = t + countNonZero - m + 1;
            if (freeVariables == 0)
            {
                double newx = 0;
                for (int j = m - 2; j > t; j--)
                    newx -= basis[j] * a[i][j];
                basis[t--] = newx / a[i][t];
            }
            else
            {
                for (int k = 0; k < freeVariables; k++)
                {
                    if (l == f)
                        basis[t--] = 1;
                    else
                        basis[t--] = 0;
                    f++;
                }
                double newx = 0;
                for (int j = m - 2; j > t; j--)
                    newx -= basis[j] * a[i][j];

                basis[t--] = newx / a[i][t];
            }
        }
        for (int i = 0; i < m - 1; i++)
            fprintf(_f, "%lf ", basis[i]);
        fprintf(_f, "\n");
        delete [] basis;
    }
}

void matrix::checkResult( char * fileName )
{
    FILE * f = fopen(fileName, "wt");
    for (int i = n - 1; i >= 0; i--)
    {
        bool isCoeffZero = true;

        for (int j = 0; j < m - 1; j++)
            if (fabs(a[i][j]) > 1e-5)
                isCoeffZero = false;
        if (isCoeffZero && fabs(a[i][m - 1]) > 1e-5)
        {
            fprintf(f, "There is no solution\n");
            fclose(f);
            return;
        }
    }

    double * x = new double[m - 1];
    bool basis = false;
    int freeVar = 0;
    int t = m - 2;
    for (int i = n - 1; i >= 0; i--)
    {
        int countZero = 0;
        int countNonZero = 0;

        for (int j = 0; j < m - 1; j++)
        {
            if (fabs(a[i][j]) < 1e-5)
                countZero++;
            else
                break;
        }
        countNonZero = m - 1 - countZero;

        if (countNonZero == 0)
            continue;

        int freeVariables = t + countNonZero - m + 1;
        freeVar += freeVariables;
        if (freeVariables == 0)
        {
            double newx = a[i][m - 1];
            for (int j = m - 2; j > t; j--)
                newx -= x[j] * a[i][j];
            x[t--] = newx / a[i][t];
        }
        else
        {
            basis = true;
            for (int k = 0; k < freeVariables; k++)
                x[t--] = 0;
            double newx = a[i][m - 1];
            for (int j = m - 2; j > t; j--)
                newx -= x[j] * a[i][j];

            x[t--] = newx / a[i][t];
        }
    }

    fprintf(f, "Partial solution:\n");
    for (int i = 0; i < m - 1; i++)
        fprintf(f, "%lf ", x[i]);
    fprintf(f, "\n\n");
    delete [] x;
    if (basis)
    {
        fprintf(f, "Basis: ");
        findBasis(freeVar, f);
    }

    fclose(f);
}

void matrix::print()
{
    cout << "Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fabs(a[i][j]) > 1e-5)
                cout << a[i][j]  << ' ';
            else
                cout << "0 ";
        }
        cout << endl;
    }
    cout << endl;
}

// destructor
matrix::~matrix()
{
    for (int i = 0; i < n; i++)
        delete [] a[i];
    delete [] a;
}
