#include <iostream>
#include "inheritance.h"
#include "matrix.h"
#include "vector.h"

using namespace std;
using namespace lab;

int main()
{
	setlocale(LC_ALL, "Rus");

	Matrix m1(2, 2);
	Matrix m2(2, 2);
	Vector v = m1*m2;

	cout << v;

	return 0;
}