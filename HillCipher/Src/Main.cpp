// Copyright (c) 2021 Tobias Briones. All rights reserved.

#include <iostream>
#include <fstream>
#include "Test.h"

using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

const string DEC_FILE_NAME = "dec.txt";
const string ENC_FILE_NAME = "enc.txt";

string read(string fileName);

void write(string str, string fileName);

void encrypt();

void decrypt();

int main()
{
    testAll();

    encrypt();
    decrypt();
}

string read(string fileName)
{
    string str;
    ifstream file(fileName);

    while (getline(file, str)) {}
    return str;
}

void write(string str, string fileName)
{
    ofstream file(fileName);

    file << str;
    file.close();
}

void encrypt()
{
    HillCipher hill(2);
    SquareMatrix26 mat(2);

    mat[0][0] = 11;
    mat[0][1] = 8;
    mat[1][0] = 3;
    mat[1][1] = 7;
    hill.setKey(mat);

    auto msg = read(DEC_FILE_NAME);
    auto enc = hill.encrypt(msg);

    write(enc, ENC_FILE_NAME);
}

void decrypt()
{
    HillCipher hill(2);
    SquareMatrix26 mat(2);

    mat[0][0] = 11;
    mat[0][1] = 8;
    mat[1][0] = 3;
    mat[1][1] = 7;
    hill.setKey(mat);

    try
    {
        auto enc = read(ENC_FILE_NAME);
        auto msg = hill.decrypt(enc);

        write(msg, DEC_FILE_NAME);
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }
}
