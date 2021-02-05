#include "matrix.h"
#include <iomanip>
#include <string>
using namespace lab;

double insert_num(double a)
{
	return a;
}

double order(double i)
{
	return i;
}

double random(int i, int k)
{
	return rand() % 10;
}

int main()
{
	try
	{
		const double arr[4] = {4, 4, 4, 4};
		matrix e(2, arr);
		matrix k(2, random);
		matrix a(2, 3.0);
		matrix b(6, 2, 4.0);
		//std::cout << a;
		//std::cout << e;
		a *= e;
		//b [1] [1] = 24;
		//std::cout << std::setw(8) << b;
		std::cout << std::setw(8) << 2 * e;
		//std::cout << a;
		//std::cout << k;
		//std::cout << b;
	}
	catch(const std::string & str)
	{
		std::cerr << str;
	}
	return 0;
}