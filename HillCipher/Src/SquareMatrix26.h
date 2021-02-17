// Copyright (c) 2021 Tobias Briones. All rights reserved.

#pragma once

#include "SquareMatrix.h"

class SquareMatrix26 : public SquareMatrix
{

private:
	static vector<int>* toVec26(vector<int>&);
	static SquareMatrix26* toMat26(SquareMatrix&);

public:
	SquareMatrix26(int);

	SquareMatrix26* operator+(const SquareMatrix26&) const;
	vector<int>* operator*(const vector<int>&) const;

};
