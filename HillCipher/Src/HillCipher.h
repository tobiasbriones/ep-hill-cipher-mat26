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

#include<string>
#include "SquareMatrix26.h"
#include "Alphabet.h"

using std::string;

class HillCipher
{

private:
    const SquareMatrix26* matPtr;

public:
    HillCipher(int);

    ~HillCipher();

    void setKey(SquareMatrix26&);

    string encrypt(string);;

    string decrypt(string);
};
