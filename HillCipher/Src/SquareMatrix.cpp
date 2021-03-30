// Copyright (c) 2021 Tobias Briones. All rights reserved.

#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(int n) :
    n(n)
{
    matrix = new int* [n];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

SquareMatrix::~SquareMatrix()
{
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

SquareMatrix* SquareMatrix::sum(const SquareMatrix& other) const
{
    if (n != other.size())
    {
        throw std::exception("Matrices must have the same size");
    }
    auto* resultPtr = new SquareMatrix(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (*resultPtr)[i][j] = matrix[i][j] + other[i][j];
        }
    }
    return resultPtr;
}

vector<int>* SquareMatrix::mul(const vector<int>& vec) const
{
    if (n != vec.size())
    {
        throw std::exception("Vector must have the same size as the matrix");
    }

    auto productPtr = new vector<int>(n);

    for (int i = 0; i < n; i++)
    {
        auto rowSum = 0;

        for (int j = 0; j < n; j++)
        {
            auto aij = matrix[j][i];
            auto xj = vec.at(j);
            rowSum += aij * xj;
        }
        (*productPtr)[i] = rowSum;
    }
    return productPtr;
}

int* SquareMatrix::operator[](int i) const
{
    return matrix[i];
}

SquareMatrix* SquareMatrix::operator+(const SquareMatrix& other) const
{
    return sum(other);
}

vector<int>* SquareMatrix::operator*(const vector<int>& vec) const
{
    return mul(vec);
}

int SquareMatrix::size() const
{
    return n;
}

int SquareMatrix::det() const
{
    return computeDeterminant(*this);
}

SquareMatrix* SquareMatrix::adj() const
{
    auto adjPtr = new SquareMatrix(n);
    getAdjoint(*this, *adjPtr);
    return adjPtr;
}

SquareMatrix* SquareMatrix::inv() const
{
    auto determinant = det();

    if (determinant == 0)
    {
        throw std::exception("The matrix must not be singular");
    }
    auto adjPtr = adj();
    auto invPtr = new SquareMatrix(n);

    // TODO implement scalar multiplication operator
    auto factor = 1 / determinant;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (*invPtr)[i][j] = factor * (*adjPtr)[i][j];
        }
    }
    delete adjPtr;
    return invPtr;
}

int SquareMatrix::computeDeterminant(const SquareMatrix& mat)
{
    int n = mat.size();

    if (n == 1)
    {
        return mat[0][0];
    }
    if (n == 2)
    {
        return (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]);
    }
    int det = 0;
    SquareMatrix submat(n - 1);

    for (int x = 0; x < n; x++)
    {
        int subi = 0;

        for (int i = 1; i < n; i++)
        {
            int subj = 0;

            for (int j = 0; j < n; j++)
            {
                if (j == x)
                {
                    continue;
                }
                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        det = det + (pow(-1, x) * mat[0][x] * computeDeterminant(submat));
    }
    return det;
}

void SquareMatrix::getMinorMat(const SquareMatrix& mat, SquareMatrix& temp, int p, int q)
{
    int n = mat.size();
    int x = 0;
    int y = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != p && j != q)
            {
                temp[x][y++] = mat[i][j];

                if (y == n - 1)
                {
                    y = 0;
                    x++;
                }
            }
        }
    }
}

void SquareMatrix::getAdjoint(const SquareMatrix& mat, SquareMatrix& adj)
{
    int n = mat.size();

    if (n == 1)
    {
        adj[0][0] = 1;
        return;
    }

    int sign = 1;
    SquareMatrix temp(n - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getMinorMat(mat, temp, i, j);

            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * temp.det();
        }
    }
}

int SquareMatrix::mod26(int value)
{
    if (value < 0)
    {
        value *= -1;
        value %= 26;
        return 26 - value;
    }
    return value % 26;
}
