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

#include "HillCipher.h"

HillCipher::HillCipher(int n)
{
    this->matPtr = new SquareMatrix26(n);
}

HillCipher::~HillCipher()
{
    delete matPtr;
}

void HillCipher::setKey(SquareMatrix26& value)
{
    if (value.det() == 0)
    {
        throw std::exception("Can't use a singular matrix as key");
    }
    auto n = matPtr->size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (*matPtr)[i][j] = value[i][j];
        }
    }
}

string HillCipher::encrypt(string msg)
{
    auto n = matPtr->size();
    auto m = msg.size();
    auto pos = 0;
    Alphabet26 alphabet;
    vector<int> vec(n);
    string enc = "";

    if (m % n != 0)
    {
        auto remaining = n - (m % n);

        for (int i = 0; i < remaining; i++)
        {
            msg += "Z";
        }
        m += remaining;
    }

    for (int i = 0; i < m; i += n)
    {
        for (int x = 0; x < n; x++)
        {
            char ch = (char) toupper(msg[i + x]);

            vec[x] = alphabet.canonicalPositionOf(ch);
        }
        auto productPtr = (*matPtr) * vec;

        for (int y = 0; y < n; y++)
        {
            int ch = (*productPtr)[y];

            enc += tolower(alphabet.chars[ch]);
        }
        delete productPtr;
    }
    return enc;
}

string HillCipher::decrypt(string enc)
{
    auto n = matPtr->size();
    auto m = enc.size();
    auto pos = 0;
    Alphabet26 alphabet;
    vector<int> vec(n);
    string msg = "";

    if ((m % n) != 0)
    {
        throw std::exception("Invalid cipher text");
    }

    for (int i = 0; i < m; i += n)
    {
        for (int y = 0; y < n; y++)
        {
            char ch = (char) toupper(enc[i + y]);

            vec[y] = alphabet.canonicalPositionOf(ch);
        }
        auto invPtr = matPtr->inv();
        auto productPtr = (*invPtr) * vec;

        delete invPtr;

        for (int x = 0; x < n; x++)
        {
            int ch = (*productPtr)[x];

            msg += tolower(alphabet.chars[ch]);
        }
        delete productPtr;
    }
    return msg;
}
