// Copyright (c) 2021 Tobias Briones. All rights reserved.

#pragma once

#include<vector>
#include<math.h>

using std::vector;

class SquareMatrix
{

private:
	int n;
	int** matrix;

	static int computeDeterminant(const SquareMatrix&);

public:
	SquareMatrix(int);
	~SquareMatrix();

	int* operator[](int) const;
	SquareMatrix* operator+(const SquareMatrix&) const;
	vector<int>* operator*(const vector<int>&) const;
	int size() const;
	int det() const;
	SquareMatrix* adj() const;
	SquareMatrix* inv() const;

};
