// Copyright (c) 2021 Tobias Briones. All rights reserved.

#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(int n) :
	n(n)
{
	matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];

		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

SquareMatrix::~SquareMatrix()
{
	for (int i = 0; i < n; i++)
	{
		delete [] matrix[i];
	}
	delete [] matrix;
}

int* SquareMatrix::operator[](int i) const {
	return matrix[i];
}

SquareMatrix* SquareMatrix::operator+(const SquareMatrix& other) const 
{
	if (n != other.size()) {
		throw "Matrices must have the same size";
	}
	auto *resultPtr = new SquareMatrix(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			(*resultPtr)[i][j] = matrix[i][j] + other[i][j];
		}
	}
	return resultPtr;
}

vector<int>* SquareMatrix::operator*(const vector<int>& vec) const
{
	if (n != vec.size()) {
		throw "Vector must have the same size as the matrix";
	}

	auto productPtr = new vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		auto rowSum = 0;

		for (int j = 0; j < n; j++)
		{
			auto aij = matrix[i][j];
			auto xj = vec.at(j);
			rowSum += aij * xj;
		}
		(*productPtr)[i] = rowSum;
	}
	return productPtr;
}

int SquareMatrix::size() const
{
	return n;
}

int SquareMatrix::det() const
{
	return computeDeterminant(*this);
}

SquareMatrix* SquareMatrix::adj() const
{
	auto* adj = new SquareMatrix(n);
	return adj;
}

SquareMatrix* SquareMatrix::inv() const
{
	auto* inv = new SquareMatrix(n);
	return inv;
}

int SquareMatrix::computeDeterminant(const SquareMatrix& mat)
{
	int n = mat.size();

	if (n == 2)
	{
		return (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]);
	}
	int det = 0;
	SquareMatrix submat(n - 1);

	for (int x = 0; x < n; x++) {
		int subi = 0;

		for (int i = 1; i < n; i++) {
			int subj = 0;

			for (int j = 0; j < n; j++) {
				if (j == x)
				{
					continue;
				}
				submat[subi][subj] = mat[i][j];
				subj++;
			}
			subi++;
		}
		det = det + (pow(-1, x) * mat[0][x] * computeDeterminant(submat));
	}
	return det;
}
