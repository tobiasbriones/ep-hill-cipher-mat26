// Copyright (c) 2021 Tobias Briones. All rights reserved.

#include <iostream>
#include <fstream>
#include "HillCipher.h"
#include "SquareMatrix.h"
#include "Test.h"

using std::string;
using std::ifstream;
using std::ofstream;

const string DEC_FILE_NAME = "dec.txt";
const string ENC_FILE_NAME = "enc.txt";

string read(string fileName);

void write(string str, string fileName);

int main()
{
    string str = read(ENC_FILE_NAME);

    cout << str << endl;

    write("messg", DEC_FILE_NAME);
    testAll();
}

string read(string fileName)
{
    string str;
    ifstream file(fileName);
    
    while (getline(file, str));
    return str;
}

void write(string str, string fileName)
{
    ofstream file(fileName);

    file << str;
    file.close();
}
