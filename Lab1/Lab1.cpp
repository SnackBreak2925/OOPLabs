#include "vector.h"
#include <iostream>
#include <cmath>
using namespace std;
using namespace lab;

int main()
{
	vector v1 = 1;
	vector v2(2, 3, 4);
	//vector v3 = v1;
	//vector v4;
	//v4.print_valTes();
	sum(v1, v2).print_values();

	/*double x, y, z;
	cout << "Insert coordinates of vector #" << vector::get_i () << endl;
	cout << "X = ";
	cin >> x;
	cout << "Y = ";
	cin >> y;
	cout << "Z = ";
	cin >> z;
	vector myVector (x, y, z);

	cout << "Insert coordinates of vector #" << vector::get_i () << endl;
	cout << "X = ";
	cin >> x;
	cout << "Y = ";
	cin >> y;
	cout << "Z = ";
	cin >> z;
	vector myVector1 (x, y, z);

	double SinTs , CosinTs, Scalar, Angle;

	Angle = angle (myVector, myVector1);
	Scalar = scalar (myVector, myVector1);
	CosinTs = cosin (myVector, myVector1);
	SinTs = sinTs (myVector, myVector1);


	cout << "Angle = " << Angle << endl;
	cout << "Scalar = " << Scalar << endl;
	cout << "Cos = " << CosinTs << endl;
	cout << "Sin = " << SinTs << endl;*/
	return 0;
}