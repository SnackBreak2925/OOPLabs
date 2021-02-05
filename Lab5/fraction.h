#pragma once
#include <iostream>

namespace lab
{
	class fraction
	{
	public:
		fraction(int = 0, int = 1);
		void reduction();
		int take_whole();
		static int gcd(int, int);
		int get_numerator() const;
		int get_denominator() const;
		void set_numerator(int);
		void set_denominator(int);
		fraction& operator += (const fraction&);
		fraction& operator -= (const fraction&);
		fraction& operator *= (const fraction&);
		fraction& operator /= (const fraction&);
		friend std::ostream& operator << (std::ostream&, const fraction&);
		friend fraction operator + (const fraction&, const fraction&);
		friend fraction operator - (const fraction&, const fraction&);
		friend fraction operator * (const fraction&, const fraction&);
		friend fraction operator / (const fraction&, const fraction&);
		friend bool operator == (const fraction& left, const fraction& right);
	private:
		int numerator;
		int denominator;
	};
}