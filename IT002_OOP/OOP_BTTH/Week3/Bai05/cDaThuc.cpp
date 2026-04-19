#include "cDaThuc.h"
#include <iostream>
#include <cmath>

using namespace std;

cDaThuc::cDaThuc() {
    bac = 0;
    heSo = new float[1];
    heSo[0] = 0;
}

cDaThuc::cDaThuc(int b) {
    bac = b;
    heSo = new float[bac + 1];
    for (int i = 0; i <= bac; i++) {
        heSo[i] = 0;
    }
}

cDaThuc::cDaThuc(const cDaThuc& other) {
    bac = other.bac;
    heSo = new float[bac + 1];
    for (int i = 0; i <= bac; i++) {
        heSo[i] = other.heSo[i];
    }
}

cDaThuc::~cDaThuc() {
    if (heSo != nullptr) {
        delete[] heSo;
    }
}

void cDaThuc::nhap() {
    cout << "Nhap bac cua da thuc: ";
    cin >> bac;
    if (heSo != nullptr) {
        delete[] heSo;
    }
    heSo = new float[bac + 1];
    for (int i = bac; i >= 0; i--) {
        cout << "Nhap he so cua x^" << i << ": ";
        cin >> heSo[i];
    }
}

void cDaThuc::xuat() {
    if (bac == 0 && heSo[0] == 0) {
        cout << "0\n";
        return;
    }
    bool first = true;
    for (int i = bac; i >= 0; i--) {
        if (heSo[i] != 0) {
            if (!first) {
                if (heSo[i] > 0) cout << " + ";
                else cout << " - ";
            }
            else {
                if (heSo[i] < 0) cout << "-";
                first = false;
            }

            float val = abs(heSo[i]);
            if (val != 1 || i == 0) cout << val;

            if (i > 0) {
                cout << "x";
                if (i > 1) cout << "^" << i;
            }
        }
    }
    if (first) cout << "0";
    cout << "\n";
}

float cDaThuc::tinhGiaTri(float x) {
    float ketQua = 0;
    for (int i = 0; i <= bac; i++) {
        ketQua += heSo[i] * pow(x, i);
    }
    return ketQua;
}

cDaThuc cDaThuc::cong(const cDaThuc& d) {
    int maxBac = (bac > d.bac) ? bac : d.bac;
    cDaThuc ketQua(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        float hs1 = (i <= bac) ? heSo[i] : 0;
        float hs2 = (i <= d.bac) ? d.heSo[i] : 0;
        ketQua.heSo[i] = hs1 + hs2;
    }
    return ketQua;
}

cDaThuc cDaThuc::tru(const cDaThuc& d) {
    int maxBac = (bac > d.bac) ? bac : d.bac;
    cDaThuc ketQua(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        float hs1 = (i <= bac) ? heSo[i] : 0;
        float hs2 = (i <= d.bac) ? d.heSo[i] : 0;
        ketQua.heSo[i] = hs1 - hs2;
    }
    return ketQua;
}