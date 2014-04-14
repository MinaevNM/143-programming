#include <iostream>
#include <cmath>

using namespace std;

union bits
{
	bits( double n );
	void show_bits(); 
	double d;
	unsigned char c[sizeof(double)];
};

bits::bits( double n ) : d(n)
{
}

void tobin( unsigned char c )
{
	for (int i = 7; i >= 0; i--)
		cout << (c / (int)pow(2., i)) % 2;
}

void bits::show_bits() 
{
	int double_size = sizeof(double);
	for (int i = double_size - 1; i >= 0; --i)
	{
		cout << "Binary representation of the byte #" << i << ": "; 
		tobin(c[i]);
		cout << "\n";
	}
}

int main()
{
	bits number(20.092013);
	number.show_bits();
	/* Если данный метод реализован верно, то
	   на экране будет выведено:
	   Binary representation of the byte #7: 01000000
	   Binary representation of the byte #6: 00110100 
	   Binary representation of the byte #5: 00010111
	   Binary representation of the byte #4: 10001110 
	   Binary representation of the byte #3: 00101001
	   Binary representation of the byte #2: 11111001
	   Binary representation of the byte #1: 11001110
	   Binary representation of the byte #0: 10001110 */

	return EXIT_SUCCESS; 
}