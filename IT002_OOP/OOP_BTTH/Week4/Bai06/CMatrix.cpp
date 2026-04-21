#include "CMatrix.h"

CVector::CVector(int dims) : n(dims) {
    v = new double[n] {0};
}

CVector::~CVector() {
    delete[] v;
}

CVector::CVector(const CVector& other) : n(other.n) {
    v = new double[n];
    for (int i = 0; i < n; i++) v[i] = other.v[i];
}

CVector& CVector::operator=(const CVector& other) {
    if (this != &other) {
        delete[] v;
        n = other.n;
        v = new double[n];
        for (int i = 0; i < n; i++) v[i] = other.v[i];
    }
    return *this;
}

double& CVector::operator[](int i) { return v[i]; }
double CVector::operator[](int i) const { return v[i]; }

CVector CVector::operator+(const CVector& other) const {
    int maxDims = (n > other.n) ? n : other.n;
    CVector kq(maxDims);
    for (int i = 0; i < maxDims; i++) {
        double val1 = (i < n) ? v[i] : 0;
        double val2 = (i < other.n) ? other.v[i] : 0;
        kq[i] = val1 + val2;
    }
    return kq;
}

CVector CVector::operator-(const CVector& other) const {
    int maxDims = (n > other.n) ? n : other.n;
    CVector kq(maxDims);
    for (int i = 0; i < maxDims; i++) {
        double val1 = (i < n) ? v[i] : 0;
        double val2 = (i < other.n) ? other.v[i] : 0;
        kq[i] = val1 - val2;
    }
    return kq;
}

istream& operator>>(istream& is, CVector& vec) {
    cout << "Nhap so chieu vector: ";
    int dims; is >> dims;
    if (dims != vec.n) {
        delete[] vec.v;
        vec.n = dims;
        vec.v = new double[vec.n];
    }
    cout << "Nhap " << vec.n << " toa do: ";
    for (int i = 0; i < vec.n; i++) is >> vec.v[i];
    return is;
}

ostream& operator<<(ostream& os, const CVector& vec) {
    os << "(";
    for (int i = 0; i < vec.n; i++) {
        os << vec.v[i] << (i < vec.n - 1 ? ", " : "");
    }
    os << ")";
    return os;
}

void CMatrix::allocateMemory(int r, int c) {
    rows = r; cols = c;
    m = new double* [rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new double[cols] {0};
    }
}

void CMatrix::freeMemory() {
    for (int i = 0; i < rows; i++) {
        delete[] m[i];
    }
    delete[] m;
}

CMatrix::CMatrix(int r, int c) { allocateMemory(r, c); }
CMatrix::~CMatrix() { freeMemory(); }

CMatrix::CMatrix(const CMatrix& other) {
    allocateMemory(other.rows, other.cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            m[i][j] = other.m[i][j];
}

CMatrix& CMatrix::operator=(const CMatrix& other) {
    if (this != &other) {
        freeMemory();
        allocateMemory(other.rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                m[i][j] = other.m[i][j];
    }
    return *this;
}

double* CMatrix::operator[](int i) { return m[i]; }
const double* CMatrix::operator[](int i) const { return m[i]; }

CMatrix CMatrix::operator+(const CMatrix& other) const {
    CMatrix kq(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            kq[i][j] = m[i][j] + other.m[i][j];
    return kq;
}

CMatrix CMatrix::operator-(const CMatrix& other) const {
    CMatrix kq(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            kq[i][j] = m[i][j] - other.m[i][j];
    return kq;
}

CMatrix CMatrix::operator*(const CMatrix& other) const {
    if (cols != other.rows) {
        cout << "\n[Loi] So cot ma tran 1 phai bang so dong ma tran 2!\n";
        return CMatrix(1, 1);
    }

    CMatrix kq(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            kq[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                kq[i][j] += m[i][k] * other.m[k][j];
            }
        }
    }
    return kq;
}

CVector CMatrix::operator*(const CVector& vec) const {
    if (cols != vec.getDims()) {
        cout << "\n[Loi] Kich thuoc khong khop de nhan Ma Tran va Vector!\n";
        return CVector(1);
    }

    CVector kq(rows);
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += m[i][j] * vec[j];
        }
        kq[i] = sum;
    }
    return kq;
}

istream& operator>>(istream& is, CMatrix& mat) {
    cout << "Nhap so dong va so cot: ";
    int r, c; is >> r >> c;
    if (r != mat.rows || c != mat.cols) {
        mat.freeMemory();
        mat.allocateMemory(r, c);
    }
    for (int i = 0; i < mat.rows; i++) {
        cout << "Nhap " << mat.cols << " phan tu dong " << i + 1 << ": ";
        for (int j = 0; j < mat.cols; j++) is >> mat[i][j];
    }
    return is;
}

ostream& operator<<(ostream& os, const CMatrix& mat) {
    for (int i = 0; i < mat.rows; i++) {
        os << "[ ";
        for (int j = 0; j < mat.cols; j++) {
            os << mat[i][j] << "\t";
        }
        os << "]\n";
    }
    return os;
}