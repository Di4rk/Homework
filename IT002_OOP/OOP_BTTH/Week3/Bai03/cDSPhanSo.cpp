#include "cDSPhanSo.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

cDSPhanSo::cDSPhanSo() {
    n = 0;
    ds = nullptr;
}

cDSPhanSo::~cDSPhanSo() {
    if (ds != nullptr) {
        delete[] ds;
    }
}

void cDSPhanSo::nhap() {
    cout << "Nhap so luong phan so: ";
    cin >> n;
    ds = new PhanSo[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << i + 1 << " (tu mau): ";
        cin >> ds[i].tu >> ds[i].mau;
        while (ds[i].mau == 0) {
            cout << "Mau phai khac 0! Nhap lai mau: ";
            cin >> ds[i].mau;
        }
        rutGon(ds[i]);
    }
}

void cDSPhanSo::xuat() {
    for (int i = 0; i < n; i++) {
        cout << ds[i].tu << "/" << ds[i].mau << "  ";
    }
    cout << endl;
}

int cDSPhanSo::gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

void cDSPhanSo::rutGon(PhanSo& ps) {
    int ucln = gcd(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
    if (ps.mau < 0) { 
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
}

float cDSPhanSo::giaTri(PhanSo ps) {
    return (float)ps.tu / ps.mau;
}

PhanSo cDSPhanSo::tinhTong() {
    PhanSo tong = { 0, 1 };
    for (int i = 0; i < n; i++) {
        tong.tu = tong.tu * ds[i].mau + ds[i].tu * tong.mau;
        tong.mau = tong.mau * ds[i].mau;
        rutGon(tong);
    }
    return tong;
}

PhanSo cDSPhanSo::timMax() {
    PhanSo max = ds[0];
    for (int i = 1; i < n; i++) {
        if (giaTri(ds[i]) > giaTri(max)) max = ds[i];
    }
    return max;
}

PhanSo cDSPhanSo::timMin() {
    PhanSo min = ds[0];
    for (int i = 1; i < n; i++) {
        if (giaTri(ds[i]) < giaTri(min)) min = ds[i];
    }
    return min;
}

bool cDSPhanSo::laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

PhanSo cDSPhanSo::timPhanSoCoTuLaSNTMax() {
    int indexMax = -1;
    int maxTu = -1e9;

    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(ds[i].tu)) {
            if (ds[i].tu > maxTu) {
                maxTu = ds[i].tu;
                indexMax = i;
            }
        }
    }
    if (indexMax == -1) return { 0, 0 }; 
    return ds[indexMax];
}

void cDSPhanSo::sapXepTang() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (giaTri(ds[i]) > giaTri(ds[j])) swap(ds[i], ds[j]);
        }
    }
}

void cDSPhanSo::sapXepGiam() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (giaTri(ds[i]) < giaTri(ds[j])) swap(ds[i], ds[j]);
        }
    }
}