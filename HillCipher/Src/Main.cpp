// Copyright (c) 2021 Tobias Briones. All rights reserved.

#include <iostream>
#include "HillCipher.h"
#include "SquareMatrix.h"

using namespace std;

void testMatAddition(); 
void testMatDeterminant();

int main()
{
    testMatAddition();
    testMatDeterminant();
}

void testMatAddition()
{
    auto mat = SquareMatrix(3);
    auto mat1 = SquareMatrix(3);

    int rows[3][3]{
        {2,-3,1},
        {2,0,-1},
        {1,4,5},
    };
    int rows1[3][3]{
        {-1,-2,-3},
        {10,11,100},
        {-1,-2,-3},
    };
    int expected[3][3]{
        {1, -5, -2},
        {12,11,99},
        {0,2,2},
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = rows[i][j];
            mat1[i][j] = rows1[i][j];
        }
    }
    auto sumPtr = mat + mat1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int* row = (*sumPtr)[i];
            int v = row[j];
            int e = expected[i][j];

            if (v != e)
            {
                cout << "FAILED: ADDITION TEST" << endl;
            }
        }
    }
    delete sumPtr;
}

void testMatDeterminant()
{
    auto mat = SquareMatrix(3);
    int rows[3][3]{
        {2,-3,1},
        {2,0,-1},
        {1,4,5},
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = rows[i][j];
        }
    }
    auto det = mat.det();

    if (det != 49)
    {
        cout << "FAILED: DETERMINANT TEST" << endl;
    }
}
