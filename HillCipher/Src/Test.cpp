// Copyright (c) 2021 Tobias Briones. All rights reserved.

#include "Test.h"

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

void testMat26Addition()
{
    auto mat = SquareMatrix26(3);
    auto mat1 = SquareMatrix26(3);

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
        {1, 21, 24},
        {12,11,21},
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
                cout << "FAILED: ADDITION26 TEST" << endl;
            }
        }
    }
    delete sumPtr;
}

void testMatVectorMultiplication()
{
    auto mat = SquareMatrix(3);
    int rows[3][3]{
        {2,-3,1},
        {2,0,-1},
        {1,4,5},
    };

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            mat[i][j] = rows[i][j];
        }
    }

    vector<int> vec{ 2, -5, 31 };
    vector<int> expected{ 25, 118, 162 };
    auto productPtr = mat * vec;

    for (int i = 0; i < 3; i++)
    {
        if ((*productPtr).at(i) != expected.at(i))
        {
            cout << "FAILED: VECTOR MULTIPLICATION TEST" << endl;
        }
    }
    delete productPtr;
}

void testMat26VectorMultiplication()
{
    auto mat = SquareMatrix26(3);
    int rows[3][3]{
        {2,-3,1},
        {2,0,-1},
        {1,4,5},
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = rows[i][j];
        }
    }

    vector<int> vec{ 2, -5, 31 };
    vector<int> expected{ 25, 14, 6};
    auto productPtr = mat * vec;

    for (int i = 0; i < 3; i++)
    {
        if ((*productPtr).at(i) != expected.at(i))
        {
            cout << "FAILED: VECTOR26 MULTIPLICATION TEST" << endl;
        }
    }
    delete productPtr;
}

void testMatDeterminant()
{
    auto mat = SquareMatrix(3);
    int rows[3][3]{
        {2,-3,1},
        {2,0,-1},
        {1,4,5},
    };

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            mat[i][j] = rows[i][j];
        }
    }
    auto det = mat.det();

    if (det != 49)
    {
        cout << "FAILED: DETERMINANT TEST" << endl;
    }
}

void testMatDeterminant26()
{
    auto mat = SquareMatrix26(3);
    int rows[3][3]{
        {10, 5, 12},
        {3, 14, 21},
        {8, 9, 11},
    };

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            mat[i][j] = rows[i][j];
        }
    }
    auto det = mat.det();

    if (det != 7)
    {
        cout << "FAILED: DETERMINANT26 TEST" << endl;
    }
}

void testMatAdjoint()
{
    auto mat = SquareMatrix(3);
    int rows[3][3]{
        {2,-3,1},
        {2,0,-1},
        {1,4,5},
    };

    auto expected = SquareMatrix(3);
    int rowsExpected[3][3]{
        {4, 19, 3},
        {-11, 9, 4},
        {8, -11, 6},
    };

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            mat[i][j] = rows[i][j];
            expected[i][j] = rowsExpected[i][j];
        }
    }
    auto adjPtr = mat.adj();

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) 
        {
            if ((*adjPtr)[i][j] != expected[i][j])
            {
                cout << "FAILED: ADJOINT TEST" << endl;
                cout << (*adjPtr)[i][j] << " has " << expected[i][j] << endl;
            }
        }
    }
    delete adjPtr;
}

void testMatInverse()
{
    auto mat = SquareMatrix(3);
    int rows[3][3]{
        {2,-3,1},
        {2,0,-1},
        {1,4,5},
    };

    auto expected = SquareMatrix(3);
    int rowsExpected[3][3]{
        {4 / 49, 19 / 49, 3 / 49},
        {-11 / 49, 9 / 49, 4 / 49},
        {8 / 49, -11 / 49, 16 / 49},
    };

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            mat[i][j] = rows[i][j];
            expected[i][j] = rowsExpected[i][j];
        }
    }
    auto invPtr = mat.inv();

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) {
            if ((*invPtr)[i][j] != expected[i][j])
            {
                cout << "FAILED: INVERSE TEST" << endl;
            }
        }
    }
    delete invPtr;
}


void testMatInverse26()
{
    auto mat = SquareMatrix26(3);
    int rows[3][3]{
        {10, 5, 12},
        {3, 14, 21},
        {8, 9, 11},
    };

    auto expected = SquareMatrix26(3);
    int rowsExpected[3][3]{
        {21, 15, 17},
        {23, 2, 16},
        {25, 4, 3},
    };

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            mat[i][j] = rows[i][j];
            expected[i][j] = rowsExpected[i][j];
        }
    }
    auto invPtr = mat.inv();

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) 
        {
            if ((*invPtr)[i][j] != expected[i][j])
            {
                cout << "FAILED: INVERSE26 TEST" << endl;
            }
        }
    }
    delete invPtr;
}

void testHillEncrypt()
{
    HillCipher hill1(2);
    SquareMatrix26 mat1(2);
    string expected1 = "delw";

    mat1[0][0] = 11;
    mat1[0][1] = 8;
    mat1[1][0] = 3;
    mat1[1][1] = 7;
    hill1.setKey(mat1);

    if (hill1.encrypt("july") != expected1)
    {
        cout << "FAILED: HILL ENCRYPT 1 TEST" << endl;
    }
}

void testHillDecrypt()
{
    HillCipher hill1(2);
    SquareMatrix26 mat1(2);
    string expected1 = "july";

    mat1[0][0] = 11;
    mat1[0][1] = 8;
    mat1[1][0] = 3;
    mat1[1][1] = 7;
    hill1.setKey(mat1);

    if (hill1.decrypt("delw") != expected1)
    {
        cout << "FAILED: HILL DECRYPT 1 TEST" << endl;
    }
}

void testAll()
{
    testMatAddition();
    testMat26Addition();
    testMatVectorMultiplication();
    testMat26VectorMultiplication();
    testMatDeterminant();
    testMatDeterminant26();
    testMatAdjoint();
    testMatInverse();
    testMatInverse26();
    testHillEncrypt();
    testHillDecrypt();
}
