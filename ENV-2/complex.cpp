#include "complex.h"
#include <cmath>
#include <iostream>

Complex::Complex() : r(0), i(0) {}

Complex::Complex(int r, int i) : r(r), i(i) {}

Complex Complex::operator+(const Complex& other)
{
	Complex result;
	result.i = i + other.i;
	result.r = r + other.r;
	return result;
}

Complex Complex::operator-(const Complex& other)
{
	Complex result;
	result.r = r - other.r;
	result.i = i - other.i;
	return result;
}

Complex Complex::operator*(const int& val)
{
	Complex result(*this);
	result.r *= val;
	result.i *= val;
	return result;
}

bool Complex::operator<(const Complex& other)
{
	return abs() < other.abs();
}


double Complex::abs() const
{
	return std::sqrt(i * i + r * r);
}

void Complex::print()
{
	if (i == 0)
		std::cout << r;
	if (i < 0)
		std::cout << r << i << 'i';
	if (i > 0)
		std::cout << r << '+' << i << 'i';
	std::cout << std::endl;
}
