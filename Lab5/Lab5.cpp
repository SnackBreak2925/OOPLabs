#include<iostream>
#include<iomanip>
#include"fraction.h"
#include"polinom.h"

using namespace std;
using namespace lab;

int main()
{
	fraction drob[] = {fraction(-1,2),fraction(1,-3),fraction(-1,-4), fraction(1,7)};
	polinom<fraction> a(3, drob);
	polinom<fraction> b(3, drob);
	cout << a << endl;
	//a *= b;
	//cout << a << endl;
	//cout << a << endl;
	cout << a - b << endl;
	//fraction z(0, 2);
	//cout << z.take_whole() << ' ' << z << endl;
	return 0;
}