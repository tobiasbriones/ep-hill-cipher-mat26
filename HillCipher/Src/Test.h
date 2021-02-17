// Copyright (c) 2021 Tobias Briones. All rights reserved.

#pragma once

#include <iostream>
#include "SquareMatrix.h"
#include "SquareMatrix26.h"
#include "HillCipher.h"

using std::cout;
using std::endl;

void testMatAddition();

void testMat26Addition();

void testMatVectorMultiplication();

void testMat26VectorMultiplication();

void testMatDeterminant();

void testMatDeterminant26();

void testMatAdjoint();

void testMatInverse();

void testMatInverse26();

void testHillEncrypt();

void testHillDecrypt();

void testAll();
