#define _USE_MATH_DEFINES
#include "vector.h"
#include <iostream>
#include <cmath>
using namespace std;

namespace lab
{
	int vector::i = 0;

	vector::vector(double a, double b, double c)
	{
		x = a;
		y = b;
		z = c;
		idintifier = i;
		i++;
		cout << "Vector #" << idintifier << " has ben created" << endl;
	}

	vector::vector(const vector& a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
		idintifier = i;
		i++;
		cout << "Vector #" << idintifier << " has ben created" << endl;
	}

	vector::~vector()
	{
		cout << "Vector #" << idintifier << " has ben deleted" << endl;
	}

	int vector::get_i()
	{
		return i;
	}

	int vector::get_idintifier() const
	{
		return idintifier;
	}

	void vector::mul_scalar(double a)
	{
		x *= a;
		y *= a;
		z *= a;
	}

	double vector::module() const
	{
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	void vector::normalization()
	{
		double mod = module();
		x /= mod;
		y /= mod;
		z /= mod;
	}

	void vector::print_values() const
	{
		cout << "X = " << x << "\t";
		cout << "Y = " << y << "\t";
		cout << "Z = " << z << endl;
	}

	void vector::correct_values_keyboard()
	{
		cout << "X = ";
		cin >> x;
		cout << "Y = ";
		cin >> y;
		cout << "Z = ";
		cin >> z;
	}

	void vector::correct_values(double a, double b, double c)
	{
		x = a;
		y = b;
		z = c;
	}

	double vector::get_x() const
	{
		return x;
	}

	double vector::get_y() const
	{
		return y;
	}
	double vector::get_z() const
	{
		return z;
	}

	void vector::copy(const vector& a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
	}

	vector sum(const vector& a, const vector& b)
	{
		vector z;
		z.correct_values(a.get_x() + b.get_x(), a.get_y() + b.get_y(), a.get_z() + b.get_z());
		return z;
	}

	vector sub(const vector& a, const vector& b)
	{
		vector z;
		z.correct_values(a.get_x() - b.get_x(), a.get_y() - b.get_y(), a.get_z() - b.get_z());
		return z;
	}

	vector mul(const vector& a, const vector& b)
	{
		vector z;
		z.correct_values(a.get_y() * b.get_z() - a.get_z() * b.get_y(), a.get_z() * b.get_x() - a.get_x() * b.get_z(), a.get_x() * b.get_y() - a.get_y() * b.get_x());
		return z;
	}

	double scalar(const vector& a, const vector& b)
	{
		return a.get_x() * b.get_x() + a.get_y() * b.get_y() + a.get_z() * b.get_z();
	}

	double cosin(const vector& a, const vector& b)
	{
		return scalar(a, b) / (a.module() * b.module());
	}

	double sinus(const vector& a, const vector& b)
	{
		vector c = mul(a, b);
		return c.module() / (a.module() * b.module());
	}

	double angle(const vector& a, const vector& b)
	{
		return atan2(sinus(a, b), cosin(a, b)) * 180 / M_PI;
	}
}
