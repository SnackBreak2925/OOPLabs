#include "fraction.h"
#include "polinom.h"
#include <string>
#include <iomanip>
using namespace lab;
using namespace std;

void f(polinom& p)
{

}

int main()
{
	double arr [] = {1, 2, 4, 3, 0, 0, 0};
	polinom a(6, arr);
	cout << a << endl;
	a.correct_deg();
	cout << a << endl;
	/*try
	{
		fraction a(15, 4);
		cout << a << endl;
		fraction b = a;
		cout << b << endl;
		a *= b;
		cout << a.take_whole() << endl;
		system("pause");

		double arr[] = {1, 2, 3, 4, 5, 6, 7};
		const int n = 5;
		polinom p(n);

		polinom e(6, arr);
		e[0] = 777;
		cout << setw(4) << e << endl;

		double dividend[] = {4, 2, 0, 5, 3};
		double divisor[] = {1, 2, 1};

		polinom l(4, dividend);
		polinom m(2, divisor);

		const polinom cx = l % m;

		polinom k = l;
		k /= m;

		cout << k << endl;

		cout << cx << endl;

		cout << cx[0] << endl;

		system("pause");

		return 0;
	}
	catch(const std::string & str)
	{
		std::cerr << str;
	}*/
	return 0;
}