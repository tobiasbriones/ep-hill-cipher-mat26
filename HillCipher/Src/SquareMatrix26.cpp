// Copyright (c) 2021 Tobias Briones. All rights reserved.

#include "SquareMatrix26.h"

SquareMatrix26::SquareMatrix26(int n) : SquareMatrix(n) {}

SquareMatrix26* SquareMatrix26::operator+(const SquareMatrix26& other) const
{
	auto baseSumPtr = sum(other);
	auto sumPtr = toMat26(*baseSumPtr);

	delete baseSumPtr;
	return sumPtr;
}

vector<int>* SquareMatrix26::operator*(const vector<int>& vec) const
{
	auto baseMulPtr = mul(vec);
	auto mulPtr = toVec26(*baseMulPtr);

	delete baseMulPtr;
	return mulPtr;
}

int SquareMatrix26::det() const
{
	return mod26(computeDeterminant(*this));
}

SquareMatrix26* SquareMatrix26::inv() const
{
	auto determinant = det();

	if (determinant == 0)
	{
		throw std::exception("The matrix must not be singular");
	}
	auto n = size();
	auto adjPtr = adj();
	auto invPtr = new SquareMatrix26(n);

	// TODO implement scalar multiplication operator
	auto factor = modInverse(determinant, 26);

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			auto product = factor * (*adjPtr)[i][j];
			(*invPtr)[i][j] = mod26(product);
		}
	}
	delete adjPtr;
	return invPtr;
}

vector<int>* SquareMatrix26::toVec26(vector<int>& vec)
{
	auto n = vec.size();
	auto vec26Ptr = new vector<int>(n);

	for (int i = 0; i < n; i++) 
	{
		(*vec26Ptr)[i] = mod26(vec[i]);
	}
	return vec26Ptr;
}

SquareMatrix26* SquareMatrix26::toMat26(SquareMatrix& mat)
{
	auto n = mat.size();
	auto mat26Ptr = new SquareMatrix26(n);

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			(*mat26Ptr)[i][j] = mod26(mat[i][j]);
		}
	}
	return mat26Ptr;
}

int SquareMatrix26::gcdExtended(int a, int b, int* x, int* y)
{
	if (a == 0)
	{
		*x = 0, * y = 1;
		return b;
	}
	int x1;
	int y1;
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}

int SquareMatrix26::modInverse(int a, int m)
{
	int x;
	int y;
	int g = gcdExtended(a, m, &x, &y);

	if (g != 1)
	{
		return -1;
	}
	return (x % m + m) % m;
}
