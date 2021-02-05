#pragma once
#ifndef VECTOR_H
#define VECTOR_H

namespace lab
{
	class vector
	{
	public:
		vector(double a = 0, double b = 0, double c = 0);
		vector(const vector& a);
		~vector();
		void mul_scalar(double);
		double module() const;
		void normalization();
		void print_values() const;
		void correct_values_keyboard();
		void correct_values(double, double, double);
		void copy(const vector&);
		double get_x() const;
		double get_y() const;
		double get_z() const;
		static int get_i();
		int get_idintifier() const;
	private:
		double x;
		double y;
		double z;
		int idintifier;
		static int i;
	};

	vector sum(const vector& a, const vector& b);
	vector sub(const vector& a, const vector& b);
	vector mul(const vector& a, const vector& b);
	double scalar(const vector& a, const vector& b);
	double cosin(const vector& a, const vector& b);
	double sinus(const vector& a, const vector& b);
	double angle(const vector& a, const vector& b);
}

#endif
