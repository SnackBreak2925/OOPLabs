#include <string>
#include "inheritance.h"

using namespace std;

namespace lab
{
	int Base::counter = 0;

	Base::Base() : rows(0), cols(0), matrix(0)
	{
		identification();
	}
	Base::Base(int rows, int cols, double a)
	{ // Квадратная с числом
		create(rows, cols, a);
	}
	Base::Base(int rows, int cols, const double *a)
	{ // Квадратная с числом
		create(rows, cols, a);
	}
	Base::Base(int size, double a)
	{  // Прямоугольная с числом
		create(size, size, a);
	}
	Base::Base(int size, double const *a)
	{  // Прямоугольная с массивом
		create(size, size, a);
	}
	Base::Base(const Base &other)
	{
		create(other.rows, other.cols, other.matrix);
	}
	Base::Base(Base &&other) : Base()
	{  //Конструктор переноса
		swap(other);
	}
	void Base::swap(Base &a)
	{
		std::swap(matrix, a.matrix);
		std::swap(cols, a.cols);
		std::swap(rows, a.rows);
	}

	Base::~Base()
	{
		cout << "Деструктор объекта: " << id << endl;
		if (matrix)
			delete [] matrix;
	}
	void Base::create(int rows, int cols, const double *a, int off)
	{
		identification();

		this->rows = rows;
		this->cols = cols;
		if (this->cols < 0 || this->rows < 0)
		{
			throw "Некорректный размер матрицы - " + to_string(id);
		}

		int size = this->rows * this->cols;
		if (size > 0)
			matrix = new double [size];
		else matrix = NULL;
		if (!a)
		{
			for (int i = 0; i < size; i++)
			{
				matrix [i] = 0;
			}
		}
		else if (a)
		{
			for (int i = 0; i < size; i++)
			{
				matrix [i] = *a;
				a += off;
			}
		}
	}
	void Base::create(int rows, int cols, double a)
	{
		create(rows, cols, &a, 0);
	}

	void Base::identification()
	{
		id = ++counter;
		cout << "Конструктор объекта: " << id << endl;
	}

	int Base::get_id() const
	{
		return id;
	}
	int Base::get_counter()
	{
		return counter;
	}

	int Base::rank () const
	{
		if (cols == 1)
			return 1;
		if (cols > 1)
			return 2;
		return 0;
	}

	bool Base::sum_ans(const Base &b) const
	{
		return (cols == b.cols && rows == b.rows);
	}
	bool Base::multip_ans(const Base &b)const
	{
		return (cols == b.rows);
	}
	Base &Base::operator=(Base &&other)
	{
		if (this != &other)
			return *this;

		if (matrix)
			delete [] matrix;

		cols = 0;
		rows = 0;
		swap(other);

		return *this;
	}
	Base &Base::operator=(const Base &other)
	{
		if (cols * rows != other.cols * other.rows)
		{
			if (matrix)
				delete [] matrix;
			if (other.matrix)
			{
				matrix = new double [other.cols * other.rows];
			}
			else
				matrix = NULL;
		}
		cols = other.cols;
		rows = other.rows;
		for (int i = 0, size = cols * rows; i < size; i++)
			matrix [i] = other.matrix [i];

		return *this;
	}
	Base &Base::operator*=(const Base &b)
	{
		if (!multip_ans(b))
			throw "Операция *= невозможна, т.к. размеры матриц " + to_string(id) + " и " + to_string(b.get_id()) + " не совпадают!";

		Base tmp(rows, b.cols);
		for (int i = 0; i < tmp.rows; i++)
			for (int j = 0; j < b.cols; j++)
				for (int k = 0; k < b.rows; k++)
					tmp.matrix [i * tmp.cols + j] += matrix [i * cols + k] * b.matrix [k * b.cols + j];

		return *this = std::move(tmp);

	}

	Base &Base::operator+=(const Base &b)
	{
		if (!sum_ans(b))
			throw "Операция += невозможна, т.к. размеры матриц " + to_string(id) + " и " + to_string(b.get_id()) + " не совпадают!";

		for (int i = 0, size = rows * cols; i < size; i++)
			matrix [i] += b.matrix [i];

		return *this;
	}
	Base &Base::operator-=(const Base &b)
	{
		if (!sum_ans(b))
			throw "Операция -= невозможна, т.к. размеры матриц " + to_string(id) + " и " + to_string(b.get_id()) + " не совпадают!";

		for (int i = 0, size = rows * cols; i < size; i++)
			matrix [i] -= b.matrix [i];

		return *this;
	}
	Base &Base::operator*=(double scal)
	{
		for (int i = 0, size = rows * cols; i < size; i++)
			matrix [i] *= scal;

		return *this;
	}

	Base operator+(const Base &a, const Base &b)
	{
		return Base(a) += b;
	}
	Base operator-(const Base &a, const Base &b)
	{
		return Base(a) -= b;
	}
	Base operator*(const Base &a, const Base &b)
	{
		return Base(a) *= b;
	}
	Base operator*(const Base &a, double k)
	{
		return Base(a) *= k;
	}
	Base operator*(double k, const Base &a)
	{
		return Base(a) *= k;
	}
	ostream &operator<<(ostream &ostream, const Base &a)
	{
		std::streamsize width = ostream.width();
		for (int i = 0; i < a.rows; i++)
		{
			for (int j = 0; j < a.cols; j++)
			{
				ostream.width(width);
				ostream << a.matrix [i * a.cols + j];
				if (!width)
					std::cout << " ";
			}
			ostream << endl;

		}
		return ostream;
	}
}

