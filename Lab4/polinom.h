#pragma once
#include <iostream>

namespace lab
{
	class polinom
	{
	public:
		explicit polinom(int = 0);
		polinom(const double*, int);
		polinom(int, const double*);
		polinom(const polinom&);
		polinom(polinom&&);
		~polinom();
		void correct_deg();
		int get_deg();
		polinom& operator = (const polinom&);
		polinom& operator = (polinom&&);
		polinom& operator += (const polinom&);
		polinom& operator -= (const polinom&);
		polinom& operator *= (const polinom&);
		polinom& operator /= (const polinom&);
		polinom& operator %= (const polinom&);
		friend polinom operator + (const polinom&, const polinom&);
		friend polinom operator - (const polinom&, const polinom&);
		friend polinom operator * (const polinom&, const polinom&);
		friend polinom operator / (const polinom&, const polinom&);
		friend polinom operator % (const polinom&, const polinom&);
		double& operator [] (int a);
		double operator [] (int a) const;
		double operator () (double) const;
		friend std::ostream& operator << (std::ostream&, const polinom&);
	private:
		double* index;
		int n;
	};
}