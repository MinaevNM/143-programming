#include "functionTests.h"

void compareTest(list< Matrix<double> > &input, list< Matrix<double> > &output)
{
    if (input.size() != output.size())
    {
        cout << "Number of matrices does not match\n";
        return;
    }
    else while (!output.empty())
    {
        Matrix<double> solution = solveMatrix(input.back());

        if (solution != output.back())
        {
            cout << "Test failed : \n";
            cout << "Solution : \n";
            solution.print();
            cout << "Output : \n";
            output.back().print();
        }
        else
            cout << "Test passed\n";

        output.pop_back();
        input.pop_back();
    }
}

void testTrinagular(list< Matrix<double> > listMatrix)
{
    cout <<  "                         test trinagular" << endl;
    while (!listMatrix.empty())
    {
        bool check = true;
        Matrix<double> matrix = listMatrix.front();
        listMatrix.pop_front();
        int height = matrix.getHeight();
        int width = matrix.getWidth();

        trinagular(matrix);
        matrix.print();

        int current = -1;

        for (int i = 0; i < height; ++i)
        {
            int j = 0;

            while (j < width && (abs(matrix[i][j]) <= ZERO)) ++j;

            if (j > current || j == width)
                current = j;
            else check = false;
        }

        if (check) cout << "Yes\n";
        else cout << "No\n";
    }
}

void testCalculate(list< Matrix<double> > listMatrix)
{
    cout << "                          test calculate" << endl;
    while (!listMatrix.empty())
    {
        bool check = true;
        Matrix<double> matrix = listMatrix.front();
        listMatrix.pop_front();
        matrix.print();
        int height = matrix.getHeight();
        int width = matrix.getWidth();
        double *roots = calculate(matrix);
        if (roots)
        {
            cout << "\nroot : ";
            for (int i = 0; i < width - 1; ++i)
                cout << roots[i] << ' ';

            for (int i = 0; i < height; ++i)
            {
                double sum = 0;
                for (int j = 0; j < width - 1; ++j)
                    sum += matrix[i][j] * roots[j];
                if (abs(sum - matrix[i][width - 1]) > 0.05)
                    check = false;
            }
            if (check)
                cout << "\nYes\n";
            else
                cout << "\nNo\n";
        }
        else
            cout << "Does not have solution\n";
    }
}

void testFindFreeVar(list< Matrix<double> > listMatrix)
{
    cout << "                        test find free variables\n";
    while (!listMatrix.empty())
    {
        Matrix<double> matrix = listMatrix.front();
        listMatrix.pop_front();
        trinagular(matrix);
        matrix.print();
        int width = matrix.getWidth();
        double *freeVar = findFreeVar(matrix);

        for (int i = 0; i < width - 1; ++i)
            cout << freeVar[i] << ' ';
        cout << "- free " << endl;
    }
}
