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

#include "SquareMatrix.h"

class SquareMatrix26 : public SquareMatrix
{

private:
    static vector<int>* toVec26(vector<int>&);

    static SquareMatrix26* toMat26(SquareMatrix&);

    static int gcdExtended(int, int, int*, int*);

    static int modInverse(int, int);

public:
    SquareMatrix26(int);

    SquareMatrix26* operator+(const SquareMatrix26&) const;

    vector<int>* operator*(const vector<int>&) const;

    int det() const;

    SquareMatrix26* inv() const;
};
