#include "matrix.h"
#include <string>
using namespace std;

namespace lab
{
	int matrix::counter = 0;

	matrix::matrix()				//по умолчанию
	{
		idintifier = counter;
		counter++;
		this->strings = 0;
		this->columns = 0;
		array = NULL;
		cout << "Matrix #" << idintifier << " has been created" << endl;
	}

	matrix::matrix(int length, double a) : matrix(length, length, a)
	{}

	matrix::matrix(int length, int width, double a) : matrix()
	{
		if(length < 0 || width < 0)
		{
			throw "Incorrect size for matrix #" + to_string(idintifier);
		}
		if(length != 0 && width != 0)
		{
			this->strings = length;
			this->columns = width;
			array = new double[strings * columns];
			for(int i = 0; i < strings * columns; i++)
			{
				array[i] = a;
			}
		}
	}

	matrix::matrix(int length, const double* a) : matrix(length, length, a)
	{}

	matrix::matrix(int length, int width, const double* a) : matrix(length, width)
	{
		for(int i = 0; i < strings * columns; i++)
		{
			array[i] = a[i];
		}
	}

	matrix::matrix(int size, double (*callback)(int, int)) : matrix(size, size, callback)
	{}

	matrix::matrix(int length, int width, double (*callback)(int, int)) : matrix(length, width)		//для прямоугольной
	{
		for(int i = 0; i < strings; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				array[i * columns + j] = callback(i, j);
			}
		}
	}

	matrix::matrix(matrix&& a) : matrix()
	{
		swap(array, a.array);
		swap(strings, a.strings);
		swap(columns, a.columns);
	}

	matrix::matrix(const matrix& a) : matrix(a.strings, a.columns, a.array)				//копирующий конструктор
	{}

	matrix::~matrix()
	{
		if(array)
			delete[] array;
		cout << "Matrix #" << idintifier << " has been deleted" << endl;
	}

	int matrix::get_counter()
	{
		return counter;
	}

	int matrix::get_id() const
	{
		return idintifier;
	}

	bool matrix::chek_mul(const matrix& a) const
	{
		return columns == a.strings;
	}

	bool matrix::chek_sum(const matrix& a) const
	{
		return (strings == a.strings && columns == a.columns);
	}

	int matrix::get_strings() const
	{
		return strings;
	}

	int matrix::get_columns() const
	{
		return columns;
	}

	double matrix::max() const
	{
		if(this->array == NULL)
			throw "Can't search min beacause matrix #" + to_string(idintifier) + " is null\n";
		double max = array[0];
		for(int i = 1; i < strings * columns; i++)
		{
			if(array[i] > max)
			{
				max = array[i];
			}
		}
		return max;
	}

	double matrix::min() const
	{
		if(this->array == NULL)
			throw "Can't search min beacause matrix #" + to_string(idintifier) + " is null";
		double min = array[0];
		for(int i = 1; i < strings * columns; i++)
		{
			if(array[i] < min)
			{
				min = array[i];
			}
		}
		return min;
	}

	double* matrix::operator [] (int a)
	{
		if(a < 0 || a >= strings)
		{
			throw "Incorrect index for matrix #" + to_string(idintifier);
		}
		return (array + a * this->columns);
	}

	const double* matrix::operator [] (int a) const
	{
		if(a < 0 || a >= strings)
		{
			throw "Incorrect index for matrix #" + to_string(idintifier);
		}
		return (array + a * this->columns);
	}

	matrix& matrix::operator = (const matrix& a)
	{
		if(this->columns * this->strings != a.strings * a.columns)
		{
			if(array)
				delete[] array;
			if(a.array)
			{
				array = new double[a.strings * a.columns];
			}
			else
			{
				array = NULL;
			}
		}
		this->strings = a.strings;
		this->columns = a.columns;

		for(int i = 0; i < strings * columns; i++)
		{
			this->array[i] = a.array[i];
		}
		return *this;
	}

	matrix& matrix::operator= (matrix&& a)
	{
		swap(array, a.array);
		swap(strings, a.strings);
		swap(columns, a.columns);
		return *this;
	}

	matrix& matrix::operator += (const matrix& a)
	{
		if(chek_sum(a))
		{
			for(int i = 0; i < strings * columns; i++)
				this->array[i] += a.array[i];
			return *this;
		}
		throw "Can't sum matrices #" + to_string(idintifier) + " and #" + to_string(a.idintifier);
	}

	matrix& matrix::operator -= (const matrix& a)
	{
		if(chek_sum(a))
		{
			for(int i = 0; i < strings * columns; i++)
				this->array[i] -= a.array[i];
			return *this;
		}
		throw "Can't sub matrices #" + to_string(idintifier) + " and #" + to_string(a.idintifier);
	}

	matrix& matrix::operator *= (const matrix& a)
	{
		if(chek_mul(a))
		{
			matrix temp(strings, a.columns, 0.0);
			for(int i = 0; i < strings; i++)
			{
				for(int j = 0; j < a.columns; j++)
				{
					for(int k = 0; k < columns; k++)
					{
						temp.array[i * temp.columns + j] += array[i * columns + k] * a.array[k * a.columns + j];
					}
				}
			}
			return *this = move(temp);
		}
		throw "Can't mul matrices #" + to_string(idintifier) + " and #" + to_string(a.idintifier);
	}

	matrix& matrix::operator *= (double a)
	{
		for(int i = 0; i < strings * columns; i++)
			this->array[i] *= a;
		return *this;
	}

	ostream& operator << (ostream& stream, const matrix& a)
	{
		streamsize size = stream.width();
		for(int i = 0; i < a.strings; i++)
		{
			for(int j = 0; j < a.columns; j++)
			{
				stream.width(size);
				stream << a.array[i * a.columns + j];
				if(!stream)
					stream << ' ';
			}
			stream << endl;
		}
		return stream;
	}

	matrix operator+ (const matrix& a, const matrix& b)
	{
		matrix c = a;
		c += b;
		return c;
	}

	matrix operator- (const matrix& a, const matrix& b)
	{
		matrix c = a;
		c -= b;
		return c;
	}

	matrix operator* (const matrix& a, const matrix& b)
	{
		matrix c = a;
		c *= b;
		return c;
	}

	matrix operator* (const matrix& a, double k)
	{
		matrix c = a;
		c *= k;
		return c;
	}

	matrix operator* (double k, const matrix& a)
	{
		matrix c = a;
		c *= k;
		return c;
	}
}