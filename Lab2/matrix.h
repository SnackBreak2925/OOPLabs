#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

namespace lab
{
	class matrix
	{
	public:
		matrix();								//по умолчанию
		explicit matrix(int, double = 0);
		matrix(int, int, double = 0);
		matrix(int, const double*);
		matrix(int, int, const double*);
		matrix(int size, double (*)(int, int));
		matrix(int length, int width, double (*)(int, int));
		matrix(const matrix& a);				//копирующий конструктор
		matrix(matrix&& a);				//конструктор перемещения
		~matrix();
		static int get_counter();
		int get_id() const;
		bool chek_mul(const matrix& a) const;
		bool chek_sum(const matrix& a) const;
		int get_strings() const;						//колво строк
		int get_columns() const;						//колво колонок
		double max() const;
		double min() const;
		double* operator [] (int a);
		const double* operator [] (int a) const;
		matrix& operator = (const matrix& a);
		matrix& operator = (matrix&& a);
		matrix& operator += (const matrix& a);
		matrix& operator -= (const matrix& a);
		matrix& operator *= (const matrix& a);			//умножение на вторую матрицу без создания новой
		matrix& operator *= (double a);
		friend std::ostream& operator << (std::ostream& stream, const matrix& a);
	private:
		int strings;			//кол-ва строк
		int columns;			//кол-во столбцов
		double* array;			//ссылка на начало массива
		int idintifier;
		static int counter;
	};

	matrix operator + (const matrix& a, const matrix& b);
	matrix operator - (const matrix& a, const matrix& b);
	matrix operator * (const matrix& a, const matrix& b);
	matrix operator * (const matrix& a, double k);
	matrix operator * (double k, const matrix& a);
}
#endif