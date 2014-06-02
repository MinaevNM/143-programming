#include <cmath>
#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

const Fraction eps(1, 100);

matrix::matrix( int _n, int _m ) : n(_n), m(_m)
{
    // TODO: все переменные должны инициализироваться при создании,
    // в том числе и массивы
    // DONE
    a = new Fraction *[n];
    for (int i = 0; i < n; i++)
        a[i] = new Fraction[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
         	a[i][j] = 0;
}

bool matrix::isEmpty()
{
	if (n == -1 && m == -1)
		return true;
	return false;
}

matrix::matrix( char * fileName )
{
    FILE *f = fopen(fileName, "rt");

    if (f == NULL)
	{
		m = n = -1;
        return;
	}
    int _n, _m;
    fscanf(f, "%i %i", &_n, &_m);

    n = _n;
    m = _m;

    a = new Fraction *[n];

    for (int i = 0; i < n; i++)
    {
        cout << endl;
        a[i] = new Fraction[m];
        for (int j = 0; j < m; j++)
        {
            int value = 0;
            fscanf(f, "%i", &value);
            a[i][j] = Fraction(value);
        }
    }

    fclose(f);
}

void matrix::subst( int s1, int s2, Fraction c )
{
    // TODO: [A] 1e-5 "Магические переменные" - зло. Следует дать ей имя.
    // DONE
    // TODO: [A] Нужно добавить проверку на положительность s1 и s2.
    // DONE
    if (s1 < 0 || s2 < 0 || s1 >= n || s2 >= n || fracAbso(c) < eps)
        return;
    for (int i = 0; i < m; i++)
        a[s2][i] -= a[s1][i] * c;
}

void matrix::mult( int s, Fraction c )
{
    if (fracAbso(c) < eps)
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
        if (fracAbso(a[i][column]) > fracAbso(a[max][column]))
            max = i;
    Swap(from, max);
}

// TODO: [A] сделать нерекурсивной
// DONE
void matrix::substFromAll( int num, int from, int column )
{
    if (fracAbso(a[num][column]) < eps)
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
        Fraction * basis = new Fraction[m - 1];
        // TODO: [A] Непонятно, что означают переменные t и f, m. Нужно дать им осознанные имена.
        // t - temporary variable, used to count free variables number
        // f - temporary variable, used to calculate shift in basis
        int t = m - 2;
        int f = 0;

        //problem
        for (int i = n - 1; i >= 0; i--)
        {
            int countZero = 0;
            int countNonZero = 0;

			for (int j = 0; j < m - 1; j++)
		    {
                if (fracAbso(a[i][j]) == 0)
                    countZero++;
                else
                    break;
            }
            countNonZero = m - 1 - countZero;

            if (countNonZero == 0)
                continue;

//            cout << "T : " << t << "countZero : " << countZero << endl;
            int freeVariables = t - countZero;
	        if (freeVariables == 0)
            {
//                cout << "\n1a :::::: " << a[i][t] << " t ::: " << t << endl;
                Fraction newx = 0; //maybe
                for (int j = m - 2; j > t; j--)
                    newx -= basis[j] * a[i][j];

//               cout << "newx : " << newx << " / " << "a : " << a[i][t] << endl;
                basis[t] = newx / a[i][t];
                --t;
            }
            else
            {
//                cout << "\n2a :::::: " << a[i][t] << " t ::: " << t << endl;
				i
                for (int k = 0; k < freeVariables; k++)
                {
                    if (l == f)
                        basis[t--] = 1;
                    else
                        basis[t--] = 0;
                    f++;
//                    cout << "After t : " << t << "a" << a[i][t] << endl;
                }
                Fraction newx(0);
                for (int j = m - 2; j > t; j--)
                    newx -= basis[j] * a[i][j];

//                cout << "newx : " << newx << " / " << "a : " << a[i][t] << endl;
                basis[t] = newx / a[i][t];
                --t;
            }
        }
        //problem

        for (int i = 0; i < m - 1; i++)
        {
            fprintf(_f, "(");
            fprintf(_f, "%i ", basis[i].mNumerator);
            fprintf(_f, "/");
            fprintf(_f, "%i", basis[i].mDenominator);
            fprintf(_f, ")");
            fprintf(_f, " ");
        }
        fprintf(_f, "\n");
        delete [] basis;
    }
}

void matrix::checkResult( char * fileName )
{
//    cout << "Matrix" << endl;
//    print();
//    cout << "Matrix" << endl;

    //nice
    FILE * f = fopen(fileName, "wt");
    for (int i = n - 1; i >= 0; i--)
    {
        bool isCoeffZero = true;

        for (int j = 0; j < m - 1; j++)
            if (fracAbso(a[i][j]) != 0) //eps
                isCoeffZero = false;
        if (isCoeffZero && fracAbso(a[i][m - 1]) != 0) //eps
        {
            fprintf(f, "There is no solution\n");
            fclose(f);
            return;
        }
    }
    //nice

    Fraction * x = new Fraction[m - 1];
    bool basis = false;
    int freeVar = 0;
    int t = m - 2;

    for (int i = n - 1; i >= 0; i--)
    {
        int countZero = 0;
        int countNonZero = 0;

        for (int j = 0; j < m - 1; j++)
        {
            if (fracAbso(a[i][j]) == 0) //eps
                countZero++;
            else
                break;
        }
        countNonZero = m - 1 - countZero;

        if (countNonZero == 0)
            continue;

//        cout << "t : " << t << "countZero " << countZero << endl;
        int freeVariables = t - countZero; //countNonZero - m + 1
        freeVar += freeVariables;
        if (freeVariables == 0)
        {
//            cout << "first" << endl;
            Fraction newx = a[i][m - 1];
            for (int j = m - 2; j > t; j--)
            {
                newx -= x[j] * a[i][j];
            }
//            cout << "here " << newx / a[i][t] << endl;
            x[t] = newx / a[i][t]; //было x[t--] = newx / a[i][t] и не работало
//            cout << "(x[] : freeVar == 0 )" << "t : " << t << " x ::: " << x[t] << endl;
             --t;
        }
        else
        {
            basis = true;
            for (int k = 0; k < freeVariables; k++)
                x[t--] = 0;

            Fraction newx = a[i][m - 1];
            for (int j = m - 2; j > t; j--)
            {
 //               cout << "x[j] " << x[j] << " a[i][j] " << a[i][j] << endl;
                newx -= x[j] * a[i][j];
            }

 //           cout << newx << " / " << a[i][t] << endl;
            x[t] = newx / a[i][t];
 //           cout << "x[j] : freeVar != 0 " << x[t] << endl;
            --t;
        }
    }


    fprintf(f, "Partial solution:\n");
    for (int i = 0; i < m - 1; i++)
    {
        fprintf(f, "(");
        fprintf(f, "%i ", x[i].mNumerator);
        fprintf(f, "/");
        fprintf(f, "%i", x[i].mDenominator);
        fprintf(f, ")");
        fprintf(f, " ");

    }

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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fracAbso(a[i][j]) > eps)
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
	if (isEmpty())
		return;

    for (int i = 0; i < n; i++)
        delete [] a[i];
    delete [] a;
}
