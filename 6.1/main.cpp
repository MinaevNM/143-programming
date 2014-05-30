#include <iostream>
#include "matrix.h"

using namespace std;

void checker( char * test, char * result )
{
    // TODO: [A] не очищается память
	// DONE
    matrix * m = new matrix(test);
    // TODO: [A] не закрывается файл. Кажется, его здесь
    // и не должно быть =)
    // DONE
	m->Gauss();
    m->checkResult(result);
	delete m;
}

int main()
{
    checker("in7.txt", "res7.txt");
    checker("in1.txt", "res1.txt");
    checker("in2.txt", "res2.txt");
    checker("in3.txt", "res3.txt");
    checker("in4.txt", "res4.txt");
    checker("in5.txt", "res5.txt");
    checker("in6.txt", "res6.txt");

    return 0;
}
