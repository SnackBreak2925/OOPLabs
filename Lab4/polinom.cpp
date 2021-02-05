#include "polinom.h"
#include <string>
#include <cmath>

using namespace std;

namespace lab
{
	polinom::polinom(int k) : polinom(k, 0)
	{}

	polinom::polinom(const double* a, int k) : polinom(k, a)
	{}

	polinom::polinom(int k, const double* a)
	{
		if(k < 0)
			throw "Negative degree";
		this->n = k;
		index = new double[n + 1];
		if(a)
			for(int i = 0; i <= n; i++)
				index[i] = a[i];
		else
			for(int i = 0; i <= n; i++)
				index[i] = 0;
	}

	polinom::polinom(const polinom& a) : polinom(a.n, a.index)
	{}

	polinom::polinom(polinom&& a) : polinom()
	{
		swap(n, a.n);
		swap(index, a.index);
	}

	polinom::~polinom()
	{
		if(index)
		{
			delete[] index;
			index = NULL;
			n = -1;
		}
	}

	void polinom::correct_deg()
	{
		if(n > 0)
		{
			int x = n;
			if(index[x] == 0)
			{
				do
				{
					x--;
				} while(x && index[x] == 0);
			}
			if(x != n)
			{
				polinom tmp(x);//!
				n = x;
				for(int i = 0; i <= n; i++)
				{
					tmp.index[i] = index[i];
				}
				swap(this->index, tmp.index);
			}
		}
	}

	int polinom::get_deg()
	{
		return n;
	}

	polinom& polinom::operator= (const polinom& a)
	{
		if(this->n != a.n)
		{
			if(index)
				delete[] index;
			this->n = a.n;
			index = new double[n + 1];
		}
		for(int i = 0; i <= n; i++)
			this->index[i] = a.index[i];
		return *this;
	}

	polinom& polinom::operator= (polinom&& a)
	{
		swap(n, a.n);
		swap(index, a.index);
		return *this;
	}

	polinom& polinom::operator+= (const polinom& a)
	{
		polinom tmp;
		if(n >= a.n)
		{
			tmp = *this;
			for(int i = 0; i <= a.n; i++)
				tmp.index[i] += this->index[i];
		}
		else
		{
			tmp = a;
			for(int i = 0; i <= n; i++)
				tmp.index[i] += this->index[i];
		}
		return *this = move(tmp);
	}

	polinom& polinom::operator-= (const polinom& a)
	{
		polinom tmp;
		if(n >= a.n)
		{
			tmp = *this;
			for(int i = 0; i <= a.n; i++)
				tmp.index[i] -= this->index[i];
		}
		else
		{
			tmp = a;
			for(int i = 0; i <= n; i++)
				tmp.index[i] -= this->index[i];
		}
		return *this = move(tmp);
	}

	polinom& polinom::operator*= (const polinom& a)
	{
		polinom tmp(this->n + a.n);
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= a.n; j++)
			{
				tmp.index[i + j] += index[i] * a.index[j];
			}
		}
		return *this = move(tmp);
	}

	polinom& polinom::operator/= (const polinom& a)
	{
		if(a.index[a.n] == 0)
			throw "Div on zero";
		if(n < a.n)
			return *this;
		int difference = n - a.n;
		polinom res(difference);
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

	polinom& polinom::operator%= (const polinom& a)
	{
		if(a.index[a.n] == 0)
			throw "Div on zero";
		if(n < a.n)
			return *this;
		double k;
		for(int i = 0; i <= n - a.n; i++)
		{
			k = index[n - i] / a.index[a.n];
			for(int j = 0; j <= a.n; j++)
				index[n - i - j] -= a.index[a.n - j] * k;
		}
		correct_deg();
		return *this;
	}

	double& polinom::operator [] (int a)
	{
		if(a < 0 || a >= n + 1)
		{
			throw "Incorrect index";
		}
		return *(index + a);
	}

	double polinom::operator [] (int a) const
	{
		if(a < 0 || a >= n + 1)
		{
			throw "Incorrect index";
		}
		return index[a];
	}

	double polinom::operator () (double x) const
	{
		double num = index[0];
		for(int i = 1; i <= n; i++)
		{
			num += index[i] * pow(x, i);
		}
		return num;
	}

	polinom operator+ (const polinom& a, const polinom& b)
	{
		polinom c = a;
		c += b;
		return c;
	}

	polinom operator- (const polinom& a, const polinom& b)
	{
		polinom c = a;
		c -= b;
		return c;
	}

	polinom operator* (const polinom& a, const polinom& b)
	{
		polinom c = a;
		c *= b;
		return c;
	}

	polinom operator/ (const polinom& a, const polinom& b)
	{
		polinom tmp = a;
		tmp /= b;
		return tmp;
	}

	polinom operator% (const polinom& a, const polinom& b)
	{
		polinom tmp = a;
		tmp %= b;
		return tmp;
	}

	ostream& operator<< (ostream& stream, const polinom& a)
	{
		streamsize size = stream.width();
		for(int i = 0; i <= a.n; i++)
		{
			stream.width(size);
			stream.setf(ios::showpos);
			stream << a.index[a.n - i];
			stream.unsetf(ios::showpos);
			if(a.n - i)
				stream << 'X' << '^' << a.n - i;
		}
		return stream;
	}
}