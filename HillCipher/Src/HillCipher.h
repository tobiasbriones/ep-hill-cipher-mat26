// Copyright (c) 2021 Tobias Briones. All rights reserved.

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
