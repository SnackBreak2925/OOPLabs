#include "fraction.h"
#include <string>
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
		if(denominator == 0)
		{
			throw "Error! Denominator should not be zero";
		}
		int tmp = gcd(numerator, denominator);
		numerator /= tmp;
		denominator /= tmp;
	}

	int fraction::take_whole()
	{
		return numerator / denominator;
	}

	int fraction::gcd(int a, int b)					//функция нахождения набольшего общего делителя
	{
		int t;
		while(b != 0)
		{
			t = b;
			b = a % b;
			a = t;
		}
		return a;
	}

	int fraction::get_numerator()
	{
		return numerator;
	}

	int fraction::get_denominator()
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

	fraction& fraction::operator += (const fraction& a)
	{
		if(this->denominator != a.denominator)
		{
			fraction tmp;
			tmp.denominator = this->denominator * a.denominator;
			tmp.numerator = this->numerator * a.denominator + a.numerator * this->denominator;
			*this = move(tmp);
		}
		else
			this->numerator += a.numerator;
		reduction();
		return *this;
	}

	fraction& fraction::operator -= (const fraction& a)
	{
		if(this->denominator != a.denominator)
		{
			fraction tmp;
			tmp.denominator = this->denominator * a.denominator;
			tmp.numerator = this->numerator * a.denominator - a.numerator * this->denominator;
			*this = move(tmp);
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

	ostream& operator << (ostream& stream, const fraction& a)
	{
		streamsize size = stream.width();
		stream.width(size);
		stream << a.numerator << '/' << a.denominator;
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
}