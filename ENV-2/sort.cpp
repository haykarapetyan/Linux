#include "sort.h"
#include "complex.h"

void sort(Complex* c, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		bool isSwaped = false;
		for (int j = 0; j < size - 1 - i; ++j)
			if (c[j + 1] < c[j])
			{
				Complex temp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp;
				isSwaped = true;
			}

		if (isSwaped == false)
			break;
	}
}
