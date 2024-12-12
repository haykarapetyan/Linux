#include "sort.h"
#include "complex.h"
#include <iostream>

int main()
{
	Complex* c = new Complex[3];
	c[0] = Complex(5,1);
	c[1] = Complex(1,5);
	c[2] = Complex(3,2);

	sort(c, 3);
	for (int i = 0; i < 3; ++i)
		arr[i].print();

	return 0;
}
