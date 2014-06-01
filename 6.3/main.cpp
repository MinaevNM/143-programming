#include <fstream>
#include "gauss.h"

const char *testCalc = "testCalculate.txt";
const char *testFindFree = "testFindFreeVar.txt";
const char *testTrin = "testTrinagular.txt";
const char *input = "in.txt";
const char *output = "out.txt";

void deleteMatrix(double **matrix, int height)
{
    for (int i = 0; i < height; ++i)
        delete []matrix[i];
    delete []matrix;
}

//из файла считываются матрицы и заносятся в лист матриц
void addToMatrixList(ifstream &inFile, list< Matrix<double> > &matrixList)
{
    int height = 0;
    int width = 0;
    inFile >> height >> width;

    double **matrix = (height * width)?
                new double *[height] : NULL;

    for (int i = 0; i < height; ++i)
    {
        matrix[i] = new double[width];
        for (int j = 0; j < width; ++j)
            inFile >> matrix[i][j];
    }
    matrixList.push_front(Matrix<double>(matrix, height, width));
    deleteMatrix(matrix, height);
}

list< Matrix<double> > recordMatrix(const char *adress)
{
    ifstream inFile;
    list< Matrix<double> > matrixList;

    inFile.open(adress);
    if (!inFile.is_open())
    {
        cout << "Error!" << endl;
        return matrixList;
    }
    else
    {
        int amountOfMatrix = 0;
        inFile >> amountOfMatrix;

        for(int i = 0; i < amountOfMatrix; ++i)
            addToMatrixList(inFile, matrixList);

        inFile.close();
        return matrixList;
    }
}

int main()
{
    list< Matrix<double> > in = recordMatrix(input);
    list< Matrix<double> > out = recordMatrix(output);

    compareTest(in, out);

//тесты для функций
    list< Matrix<double> > calc = recordMatrix(testCalc);
    list< Matrix<double> > free = recordMatrix(testFindFree);
    list< Matrix<double> > trin = recordMatrix(testTrin);
    testTrinagular(trin);
    testCalculate(calc);
    testFindFreeVar(free);
    return 0;
}



