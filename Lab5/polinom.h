#pragma once
#ifndef POLYNOM_H
#define POLYNOM_H
#include <iostream>

namespace lab
{
	template <class T>
	class polinom
	{
	public:
		explicit polinom(int = 0);
		polinom(const T*, int);
		polinom(int, const T*);
		polinom(const polinom&);
		polinom(polinom&&);
		~polinom();
		void correct_deg();
		int get_deg() const;
		polinom& operator = (const polinom&);
		polinom& operator = (polinom&&);
		polinom& operator += (const polinom&);
		polinom& operator -= (const polinom&);
		polinom& operator *= (const polinom&);
		polinom& operator /= (const polinom&);
		polinom& operator %= (const polinom&);
		template <class T>
		friend polinom<T> operator + (const polinom<T>&, const polinom<T>&);
		template <class T>
		friend polinom<T> operator - (const polinom<T>&, const polinom<T>&);
		template <class T>
		friend polinom<T> operator * (const polinom<T>&, const polinom<T>&);
		template <class T>
		friend polinom<T> operator / (const polinom<T>&, const polinom<T>&);
		template <class T>
		friend polinom<T> operator % (const polinom<T>&, const polinom<T>&);
		T& operator [] (int a);
		const T& operator [] (int a) const;
		T operator () (const T&) const;
		template <class T>
		friend std::ostream& operator << (std::ostream&, const polinom<T>&);
	private:
		T* index;
		int n;
		static const T zero;
	};
}

#include "polinom.cpp"
#endif POLYNOM_H