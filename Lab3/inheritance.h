#ifndef BASE_H
#define BASE_H

#include <iostream>

namespace lab
{
	class Base
	{
	protected:
		double* matrix;
		int rows, cols, id;
		static int counter;
		void identification();
		void swap(Base& a);
		Base();
		Base(int rows, int cols, double a);
		Base(int rows, int cols, const double* a);
		Base(int size, double a);
		Base(int size, const double* a);
		Base(const Base& other);
		Base(Base&& other);
	private:
		void create(int rows, int cols, const double* a, int = 1);
		void create(int rows, int cols, double a);
	public:
		virtual ~Base();
		int get_id() const;
		static int get_counter();
		virtual int rank() const;
		bool sum_ans(const Base& b) const;
		bool multip_ans(const Base& b) const;
		Base& operator=(Base&& other);
		Base& operator=(const Base& other);
		Base& operator*=(const Base& b);
		friend Base operator*(const Base& a, const Base& b);
		Base& operator*=(double scal);
		friend Base operator*(const Base& a, double k);
		friend Base operator*(double k, const Base& a);
		Base& operator+=(const Base& b);
		Base& operator-=(const Base& b);
		friend Base operator+(const Base& a, const Base& b);
		friend Base operator-(const Base& a, const Base& b);
		friend std::ostream& operator <<(std::ostream& stream, const Base& a);
	};
}

#endif BASE_H
