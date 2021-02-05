#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

namespace lab
{
	class matrix
	{
	public:
		matrix();								//�� ���������
		explicit matrix(int, double = 0);
		matrix(int, int, double = 0);
		matrix(int, const double*);
		matrix(int, int, const double*);
		matrix(int size, double (*)(int, int));
		matrix(int length, int width, double (*)(int, int));
		matrix(const matrix& a);				//���������� �����������
		matrix(matrix&& a);				//����������� �����������
		~matrix();
		static int get_counter();
		int get_id() const;
		bool chek_mul(const matrix& a) const;
		bool chek_sum(const matrix& a) const;
		int get_strings() const;						//����� �����
		int get_columns() const;						//����� �������
		double max() const;
		double min() const;
		double* operator [] (int a);
		const double* operator [] (int a) const;
		matrix& operator = (const matrix& a);
		matrix& operator = (matrix&& a);
		matrix& operator += (const matrix& a);
		matrix& operator -= (const matrix& a);
		matrix& operator *= (const matrix& a);			//��������� �� ������ ������� ��� �������� �����
		matrix& operator *= (double a);
		friend std::ostream& operator << (std::ostream& stream, const matrix& a);
	private:
		int strings;			//���-�� �����
		int columns;			//���-�� ��������
		double* array;			//������ �� ������ �������
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