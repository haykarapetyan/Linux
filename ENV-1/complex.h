#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
	int r;
	int i;
public:
	Complex();
	Complex(int r, int i);
	bool operator<(const Complex& other);
	Complex operator+(const Complex& other);
	Complex operator-(const Complex& ohter);
	Complex operator*(const int& val);
	double abs() const;
	void print();
};

#endif
