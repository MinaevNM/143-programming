#include "gauss.h"

//главные функции

//возвращает матрицу, на первом месте в которой частное решение,
//далее базисные вектора, если есть
Matrix<double> solveMatrix(Matrix<double> matrix)
{
    trinagular(matrix);
    double *freeVar = findFreeVar(matrix);
    double *particular = findParticalSolution(matrix, freeVar);
    Matrix<double> basis = findBasis(matrix, freeVar);

    int height = basis.getHeight() + 1;
    int width = basis.getWidth();

    double **solution = new double *[height];

    if (particular)
    {
        solution[0] = new double [width];
        for (int i = 0; i < width; ++i)
            solution[0][i] = particular[i];

        for (int i = 1; i < height; ++i)
        {
            solution[i] = new double [width];
            for (int j = 0; j < width; ++j)
                solution[i][j] = basis[i - 1][j];
        }
        return Matrix<double>(solution, height, width);
    }
    return Matrix<double>(NULL, 0, 0);
}

//приведение к треугольному виду
void trinagular(Matrix<double> &matrix)
{
    int height = matrix.getHeight();
    int width = matrix.getWidth();

    for (int column = 0, line = 0; column < width; ++column)
    {
        int i = line;
        bool foundNullColumn = false;

        while (i < height)
        {
            if (!foundNullColumn && abs(matrix[i][column]) > ZERO)
            {
                swap(matrix[line++], matrix[i]);
                if (line >= height) break;
                else i = line;
                foundNullColumn = true;
            }
            if (foundNullColumn && abs(matrix[i][column]) > ZERO)
                substructLines(matrix[i], matrix[line - 1], column, width);

            ++i;
        }
    }
}

//найти столбцы свободных коэфициентов
double *findFreeVar(const Matrix<double> &matrix)
{
    int height = matrix.getHeight();
    int width = matrix.getWidth();
    int last = width - 1;
    double *freeVar = new double[last];
    fill(freeVar, last, nil);

    int column = 0;
    int line = 0;

    while (column < last && line < height)
    {
        while (column < last && abs(matrix[line][column]) <= ZERO)
            freeVar[column++] = freeCoefMark;
        ++column;
        ++line;
    }
    if (column < last)
        for (int j = column; j < last; ++j)
            if (matrix[height - 1][j]) freeVar[j] = freeCoefMark;
    return freeVar;
}

//посчитать матрицу (предполагается, что она имеет треугольный вид)
double *calculate(const Matrix<double> &matrix)
{
    int height = matrix.getHeight();
    int width = matrix.getWidth();
    int last = width - 1;
    double *roots = new double[last];

    //по умолчанию все корни - единицы
    fill(roots, last, 1);

    for (int i = height - 1; i >= 0; --i)
    {
        int j = 0;

        while (j < width && abs(matrix[i][j]) < ZERO) ++j;

        if (j == width - 1)
        {
            delete roots;
            roots = NULL;
            break;
        }
        else if (j != width)
            roots[j] = findRoot(matrix, roots, i, j);
    }
    return roots;
}

//находим частное решение (обнуляем столбцы свободных переменных и решаем матрицу)
double *findParticalSolution(Matrix<double> matrix, const double *freeVar)
{
    int height = matrix.getHeight();
    int width = matrix.getWidth();
    int last = width - 1;

    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width - 1; ++j)
            matrix[i][j] = freeVar[j]? 0 : matrix[i][j];

    double *result = calculate(matrix);
    //если решение есть, ставим нули туда, где столбцы обнулялись
    //сейчас там единицы, которые мы ставили по умолчанию
    if (result)
    {
        for (int j = 0; j < last; ++j)
            if (freeVar[j] == freeCoefMark)
                result[j] = 0;
    }

    return result;
}

//ищем базис (обнуляем последний столбец,
//поочередно оставляем необнуленными по одному столбцу свободных переменных
//и решаем полученную матрицу)
Matrix<double> findBasis(const Matrix<double> &matrix, double *freeVar)
{
    int width = matrix.getWidth();
    int last = width - 1;
    int colBasis = getColBasis(freeVar, last);
    double **basis = NULL;

    if (colBasis) basis = new double *[colBasis];
    else return Matrix<double>(NULL, 0, 0);

    colBasis = 0;
    for (int i = 0; i < width - 1; ++i)
        if (freeVar[i])
        {
            Matrix<double> curMatrix = matrix;
            createNullLastColumn(curMatrix);

            freeVar[i] = nil;
            //находим базисные вектора, попутно запихивая их в матрицу базисов
            basis[colBasis++] = findParticalSolution(curMatrix, freeVar);
            freeVar[i] = freeCoefMark;
        }
    return Matrix<double>(basis, colBasis, last);
}

//служебные функции
void fill(double *line, int length, double fillElement)
{
    for (int i = 0; i < length; ++i)
        line[i] = fillElement;
}

double findRoot(const Matrix<double> &matrix, const double *roots, int line, int column)
{
    int last = matrix.getWidth() - 1;
    double sum = 0;

    for (int k = column + 1; k < last; ++k)
        sum += matrix[line][k] * roots[k];
    double result = (matrix[line][last] - sum) / matrix[line][column];

    return (abs(result) <= ZERO)? 0 : result;
}

void substructLines(double *first, double *second, int column, int width)
{
    double factor = second[column] / first[column];

    for (int j = column; j < width; ++j)
    {
        double result = first[j] * factor - second[j];
        first[j] = (abs(result) <= ZERO)? 0 : result;
    }
}

int getColBasis(const double *freeVar, int width)
{
    int colBasis = 0;

    for (int i = 0; i < width; ++i)
        if (freeVar) ++colBasis;

    return colBasis;
}

void createNullLastColumn(Matrix<double> &matrix)
{
    int height = matrix.getHeight();
    int last = matrix.getWidth() - 1;

    for (int i = 0; i < height; ++i)
        matrix[i][last] = 0;
}
