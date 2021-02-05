#include <string>
#include "matrix.h"

using namespace std;

namespace lab
{
	Matrix::Matrix() : Base()
	{}

	Matrix::Matrix(int rows, int cols, double a) : Base(rows, cols, a)
	{}
	Matrix::Matrix(int rows, int cols, const double* a) : Base(rows, cols, a)
	{}

	Matrix::Matrix(int size, double a) : Base(size, size, a)
	{}
	Matrix::Matrix(int size, const double* a) : Base(size, size, a)
	{}

	Matrix::Matrix(const Matrix& other) : Base(other)
	{}
	Matrix::Matrix(const Base& other) : Base(other)
	{}

	Matrix::Matrix(Base&& other) : Base(std::move(other))
	{}
	Matrix::Matrix(Matrix&& other) : Base(std::move(other))
	{}

	Matrix::~Matrix()
	{}
	int Matrix::getCols() const
	{
		return cols;
	}
	int Matrix::getRows() const
	{
		return rows;
	}
	double* Matrix::operator[](int num)
	{
		if(num >= rows || num < 0)
		{
			throw "Ёлемент в матрицe - " + to_string(id) + " не существует!";
		}

		return matrix + num * rows;
	}
	const double* Matrix::operator[](int num) const
	{
		if(num >= rows || num < 0)
		{
			throw "Ёлемент в матрицe - " + to_string(id) + " не существует!";
		}

		return matrix + num * rows;
	}
	Matrix& Matrix::operator=(const Base& other)
	{
		Base::operator=(other);
		return *this;
	}
	Matrix& Matrix::operator=(Base&& other)
	{
		if(this != &other) return *this;

		Base::operator=(std::move(other));

		return *this;
	}
	Matrix& Matrix::operator=(Matrix&& other)
	{
		if(this != &other) return *this;

		Base::operator=(std::move(other));

		return *this;
	}
}