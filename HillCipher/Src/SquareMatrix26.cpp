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

vector<int>* SquareMatrix26::toVec26(vector<int>& vec)
{
	auto n = vec.size();
	auto vec26Ptr = new vector<int>(n);

	for (int i = 0; i < n; i++) {
		(*vec26Ptr)[i] = mod26(vec[i]);
	}
	return vec26Ptr;
}

SquareMatrix26* SquareMatrix26::toMat26(SquareMatrix& mat)
{
	auto n = mat.size();
	auto mat26Ptr = new SquareMatrix26(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			(*mat26Ptr)[i][j] = mod26(mat[i][j]);
		}
	}
	return mat26Ptr;
}
