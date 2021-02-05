#include "fraction.h"
#include <string>
#include <sstream>
using namespace std;

namespace lab
{

	fraction::fraction(int a, int b) 					//конструктор для заданных чисел
	{
		numerator = a;
		denominator = b;
		reduction();
	}

	void fraction::reduction()				//метод для сокращения дробей
	{
		if (denominator == 0)//!
		{
			throw "Error! Denominator should not be zero";
		}
		int tmp = gcd(this->numerator, this->denominator);
		numerator /= tmp;
		denominator /= tmp;
		if (denominator < 0)
		{
			denominator = -denominator;
			numerator = -numerator;
		}
	}

	int fraction::take_whole()//!
	{
		int whole = numerator / denominator;
		numerator %= denominator;
		return whole;
	}

	int fraction::gcd(int a, int b)					//функция нахождения набольшего общего делителя
	{
		int t;
		while (b != 0)
		{
			t = b;
			b = a % b;
			a = t;
		}
		return a;
	}

	int fraction::get_numerator() const
	{
		return numerator;
	}

	int fraction::get_denominator() const
	{
		return denominator;
	}

	void fraction::set_numerator(int a)
	{
		numerator = a;
		reduction();
	}

	void fraction::set_denominator(int a)
	{
		denominator = a;
		reduction();
	}

	fraction& fraction::operator += (const fraction& a)//!
	{
		if (this->denominator != a.denominator)
		{
			this->numerator = this->numerator * a.denominator + a.numerator * this->denominator;
			this->denominator = this->denominator * a.denominator;
		}
		else
			this->numerator += a.numerator;
		reduction();
		return *this;
	}

	fraction& fraction::operator -= (const fraction& a)
	{
		if (this->denominator != a.denominator)
		{
			this->numerator = this->numerator * a.denominator - a.numerator * this->denominator;
			this->denominator = this->denominator * a.denominator;
		}
		else
			this->numerator -= a.numerator;
		reduction();
		return *this;
	}

	fraction& fraction::operator *= (const fraction& a)
	{
		this->numerator *= a.numerator;
		this->denominator *= a.denominator;
		reduction();
		return *this;
	}

	fraction& fraction::operator /= (const fraction& a)
	{
		this->numerator *= a.denominator;
		this->denominator *= a.numerator;
		reduction();
		return *this;
	}

	ostream& operator << (ostream& stream, const fraction& a)//!
	{
		stringstream ss;
		if (a.denominator == 1)
			ss << a.numerator;
		else
			ss << a.numerator << '/' << a.denominator;
		stream << ss.str();
		//stream << a.numerator << '/' << a.denominator;
		return stream;
	}

	fraction operator+ (const fraction& a, const fraction& b)
	{
		fraction c = a;
		c += b;
		return c;
	}

	fraction operator- (const fraction& a, const fraction& b)
	{
		fraction c = a;
		c -= b;
		return c;
	}

	fraction operator* (const fraction& a, const fraction& b)
	{
		fraction c = a;
		c *= b;
		return c;
	}

	fraction operator/ (const fraction& a, const fraction& b)
	{
		fraction c = a;
		c /= b;
		return c;
	}
	bool operator==(const fraction& left, const fraction& right)//!
	{
		return (left.denominator == right.denominator && left.numerator == right.numerator);
	}
}