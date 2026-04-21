#pragma once
#include <iostream>
using namespace std;

class CVector {
private:
    int n;
    double* v;

public:
    CVector(int dims = 1);
    ~CVector();
    CVector(const CVector& other);
    CVector& operator=(const CVector& other);

    int getDims() const { return n; }

    double& operator[](int i);
    double operator[](int i) const;

    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;

    friend istream& operator>>(istream& is, CVector& vec);
    friend ostream& operator<<(ostream& os, const CVector& vec);
};

class CMatrix {
private:
    int rows, cols;
    double** m;

    void allocateMemory(int r, int c);
    void freeMemory();

public:
    CMatrix(int r = 1, int c = 1);
    ~CMatrix();
    CMatrix(const CMatrix& other);
    CMatrix& operator=(const CMatrix& other);

    double* operator[](int i);
    const double* operator[](int i) const;

    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator-(const CMatrix& other) const;

    CMatrix operator*(const CMatrix& other) const;
    CVector operator*(const CVector& vec) const;

    friend istream& operator>>(istream& is, CMatrix& mat);
    friend ostream& operator<<(ostream& os, const CMatrix& mat);
};