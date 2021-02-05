#pragma once
#ifndef POLYNOM
#define POLYNOM

#include "polinom.h"
#include <string>
#include <cmath>

using namespace std;

namespace lab
{
	template <class T>
	const T polinom<T>::zero = T(0);

	template <class T>
	polinom<T>::polinom(int k) : polinom<T>(k, 0)
	{}

	template <class T>
	polinom<T>::polinom(const T* a, int k) : polinom<T>(k, a)
	{}

	template <class T>
	polinom<T>::polinom(int k, const T* a)
	{
		if(k < 0)
			throw "Negative degree";
		if(this->n = k, index = new T[n + 1], a)
			for(int i = 0; i <= n; i++)
				index[i] = a[i];
		else
			for(int i = 0; i <= n; i++)
				index[i] = 0;
	}

	template <class T>
	polinom<T>::polinom(const polinom<T>& a) : polinom<T>(a.n, a.index)
	{}

	template <class T>
	polinom<T>::polinom(polinom<T>&& a) : polinom()
	{
		swap(n, a.n);
		swap(index, a.index);
	}

	template <class T>
	polinom<T>::~polinom()
	{
		if(index)
		{
			delete[] index;
			index = NULL;
			n = -1;
		}
	}

	template <class T>
	void polinom<T>::correct_deg()
	{
		if(n > 0)
		{
			int x = n;
			if(index[x] == zero)
			{
				do
				{
					x--;
				} while(x && index[x] == zero);
			}
			if(x != n)
			{
				polinom<T> tmp(x);//!
				n = x;
				for(int i = 0; i <= n; i++)
				{
					tmp.index[i] = index[i];
				}
				swap(this->index, tmp.index);
			}
		}
	}

	template <class T>
	int polinom<T>::get_deg() const
	{
		return n;
	}

	template <class T>
	polinom<T>& polinom<T>::operator= (const polinom<T>& a)
	{
		if(this->n != a.n)
		{
			if(index)
				delete[] index;
			this->n = a.n;
			index = new T[n + 1];
		}
		for(int i = 0; i <= n; i++)
			this->index[i] = a.index[i];
		return *this;
	}

	template <class T>
	polinom<T>& polinom<T>::operator= (polinom<T>&& a)
	{
		swap(n, a.n);
		swap(index, a.index);
		return *this;
	}

	template <class T>
	polinom<T>& polinom<T>::operator+= (const polinom<T>& a)//!
	{
		if(n < a.n)
		{
			polinom<T> tmp(a);
			for(int i = 0; i <= this->n; i++)
				tmp.index[i] += this->index[i];
			swap(tmp, *this);
		}
		else
		{
			for(int i = 0; i <= n; i++)
				this->index[i] += a.index[i];
		}
		return *this;
	}

	template <class T>
	polinom<T>& polinom<T>::operator-= (const polinom<T>& a)//!
	{
		if(n < a.n)
		{
			polinom<T> tmp(a);
			for(int i = 0; i <= tmp.n; i++)
				tmp.index[i] *= -1;//-tmp.index[i];
			for(int i = 0; i <= n; i++)
				tmp.index[i] += this->index[i];
			swap(tmp, *this);
		}
		else
		{
			for(int i = 0; i <= n; i++)
				this->index[i] -= a.index[i];
		}
		correct_deg();
		return *this;
	}

	template <class T>
	polinom<T>& polinom<T>::operator*= (const polinom<T>& a)
	{
		polinom<T> tmp(this->n + a.n);
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= a.n; j++)
			{
				tmp.index[i + j] += index[i] * a.index[j];
			}
		}
		return *this = move(tmp);
	}

	template <class T>
	polinom<T>& polinom<T>::operator/= (const polinom<T>& a)
	{
		if(a.index[a.n] == zero)
			throw "Div on zero";
		if(n < a.n)
		{
			polinom<T> res(0);
			return res;
		}
		int difference = n - a.n;
		polinom<T> res(difference);
		for(int i = 0; i <= difference; i++)
		{
			res.index[difference - i] = index[n - i] / a.index[a.n];
			for(int j = 0; j <= a.n; j++)
			{
				index[n - j - i] -= a.index[a.n - j] * res.index[difference - i];
			}
		}
		res.correct_deg();
		return *this = move(res);
	}

	template <class T>
	polinom<T>& polinom<T>::operator%= (const polinom<T>& a)
	{
		if(a.index[a.n] == zero)
			throw "Div on zero";
		if(n < a.n)
			return *this;
		T k;
		for(int i = 0; i <= n - a.n; i++)
		{
			k = index[n - i] / a.index[a.n];
			for(int j = 0; j <= a.n; j++)
				index[n - i - j] -= a.index[a.n - j] * k;
		}
		correct_deg();
		return *this;
	}

	template <class T>
	T& polinom<T>::operator [] (int a)
	{
		if(a < 0 || a > n)
		{
			throw "Incorrect index";
		}
		return *(index + a);
	}

	template <class T>
	const T& polinom<T>::operator [] (int a) const
	{
		if(a < 0 || a > n)
		{
			throw "Incorrect index";
		}
		return *(index + a);
	}

	template <class T>
	T polinom<T>::operator () (const T& x) const
	{
		T num = index[0];
		T pow = x;
		for(int i = 1; i <= n; i++)
		{
			num += index[i] * pow;
			pow *= x;
		}
		return num;
	}

	template <class T>
	polinom<T> operator+ (const polinom<T>& a, const polinom<T>& b)
	{
		polinom<T> c = a;
		c += b;
		return c;
	}

	template <class T>
	polinom<T> operator- (const polinom<T>& a, const polinom<T>& b)
	{
		polinom<T> c = a;
		c -= b;
		return c;
	}

	template <class T>
	polinom<T> operator* (const polinom<T>& a, const polinom<T>& b)
	{
		polinom<T> c = a;
		c *= b;
		return c;
	}

	template <class T>
	polinom<T> operator/ (const polinom<T>& a, const polinom<T>& b)
	{
		polinom<T> tmp = a;
		tmp /= b;
		return tmp;
	}

	template <class T>
	polinom<T> operator% (const polinom<T>& a, const polinom<T>& b)
	{
		polinom<T> tmp = a;
		tmp %= b;
		return tmp;
	}

	template <class T>
	ostream& operator<< (ostream& stream, const polinom<T>& a)
	{
		streamsize size = stream.width();
		for(int i = 0; i <= a.n; i++)
		{
			stream.width(size);
			stream << a.index[a.n - i];
			if(a.n - i)
				stream << "*X^" << a.n - i;
			cout << ' ';
		}
		return stream;
	}
}
#endif POLYNOM