/*
 * Copyright (c) 2021 Tobias Briones. All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * This file is part of Example Project: Hill Cipher Mat26.
 *
 * This source code is licensed under the MIT License found in the
 * LICENSE file in the root directory of this source tree or at
 * https://opensource.org/licenses/MIT.
 */

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
