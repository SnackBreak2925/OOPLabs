#ifndef VECTOR_H
#define VECTOR_H

#include "inheritance.h"
#include <iostream> 

namespace lab
{
	class Vector : public Base
	{
	public:
		Vector();
		explicit Vector(int size, double a = 0);
		Vector(int size, const double* a);
		Vector(const Vector& other);
		Vector(const Base& other);
		Vector(Base&& other);
		Vector(Vector&& other);
		~Vector();
		int getSize() const;
		double& operator[](int num);
		double operator[](int num) const;
		Vector& operator=(const Base& other);
		Vector& operator=(Base&& other);
		Vector& operator=(Vector&& other);
	};
}
#endif VECTOR_H
