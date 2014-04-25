#include <iostream>

using namespace std;

class NegativeException {};
class WrongNumber
{
public:
	int index;
	WrongNumber( int i ) : index(i)
	{
	}
};

double g( int n, double * A )
{
	double s = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] < 0)
			throw NegativeException();
		else if (A[i] < 10 || A[i] > 100)
			throw WrongNumber(i);
		s += A[i];
	}
	return s / n;
}

double f()
{
	int n;
	cin >> n;
	double * A = new double[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	double res;
	bool flag = true;

	while (flag)
	{
	    try
	    {
		   res = g(n, A);
		   flag = false;
     	}
	    catch (NegativeException)
      	{
	    	delete [] A;
		    throw NegativeException();
    	}
	    catch (WrongNumber w)
     	{
	    	cout << "Reenter number " << w.index + 1 << endl;
		    cin >> A[w.index];		
	    }
    }
	delete [] A;
	return res;
}

void main()
{
	double r = 0;
	try
	{
		r = f();
		cout << r << endl;
	}
	catch (NegativeException)
	{
		cout << "Negative number found" << endl;
	}
}