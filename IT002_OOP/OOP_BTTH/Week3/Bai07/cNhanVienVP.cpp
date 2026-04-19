#define _CRT_SECURE_NO_WARNINGS
#include "cNhanVienVP.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

cNhanVienVP::cNhanVienVP() {
    maNV[0] = '\0';
    hoTen[0] = '\0';
    ngaySinh = 1;
    thangSinh = 1;
    namSinh = 1990;
    luong = 0;
}

cNhanVienVP::~cNhanVienVP() {}

float cNhanVienVP::getLuong() {
    return luong;
}

int cNhanVienVP::getNamSinh() {
    return namSinh;
}

int cNhanVienVP::getThangSinh() {
    return thangSinh;
}

int cNhanVienVP::getNgaySinh() {
    return ngaySinh;
}

void cNhanVienVP::setMaNV(const char* ma) {
    strncpy(maNV, ma, 19);
    maNV[19] = '\0';
}

void cNhanVienVP::setHoTen(const char* ten) {
    strncpy(hoTen, ten, 49);
    hoTen[49] = '\0';
}

void cNhanVienVP::setNgaySinh(int d, int m, int y) {
    ngaySinh = d;
    thangSinh = m;
    namSinh = y;
}

void cNhanVienVP::setLuong(float l) {
    luong = l;
}

void cNhanVienVP::nhap() {
    cout << "Nhap ma NV: ";
    cin >> ws;
    cin.getline(maNV, 20);

    cout << "Nhap ho ten: ";
    cin.getline(hoTen, 50);

    cout << "Nhap ngay thang nam sinh (vd: 15 8 2002): ";
    cin >> ngaySinh >> thangSinh >> namSinh;

    cout << "Nhap luong: ";
    cin >> luong;
}

void cNhanVienVP::xuat() {
    cout << "Ma NV: " << maNV << " | Ten: " << hoTen
        << " | NS: " << ngaySinh << "/" << thangSinh << "/" << namSinh
        << " | Luong: " << fixed << setprecision(0) << luong << "\n";
}

cDSNhanVienVP::cDSNhanVienVP() {
    ds = nullptr;
    n = 0;
}

cDSNhanVienVP::~cDSNhanVienVP() {
    if (ds != nullptr) {
        delete[] ds;
    }
}

void cDSNhanVienVP::nhap() {
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    if (ds != nullptr) {
        delete[] ds;
    }
    ds = new cNhanVienVP[n];

    for (int i = 0; i < n; i++) {
        cout << "--- Nhap nhan vien thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }
}

void cDSNhanVienVP::xuatDanhSach() {
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }
}

cNhanVienVP cDSNhanVienVP::timNhanVienLuongCaoNhat() {
    if (n == 0) return cNhanVienVP();
    cNhanVienVP maxLuong = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].getLuong() > maxLuong.getLuong()) {
            maxLuong = ds[i];
        }
    }
    return maxLuong;
}

float cDSNhanVienVP::tinhTongLuong() {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].getLuong();
    }
    return tong;
}

cNhanVienVP cDSNhanVienVP::timNhanVienTuoiCaoNhat() {
    if (n == 0) return cNhanVienVP();
    cNhanVienVP oldest = ds[0];
    for (int i = 1; i < n; i++) {
        bool isOlder = false;
        if (ds[i].getNamSinh() < oldest.getNamSinh()) {
            isOlder = true;
        }
        else if (ds[i].getNamSinh() == oldest.getNamSinh()) {
            if (ds[i].getThangSinh() < oldest.getThangSinh()) {
                isOlder = true;
            }
            else if (ds[i].getThangSinh() == oldest.getThangSinh()) {
                if (ds[i].getNgaySinh() < oldest.getNgaySinh()) {
                    isOlder = true;
                }
            }
        }
        if (isOlder) {
            oldest = ds[i];
        }
    }
    return oldest;
}

void cDSNhanVienVP::sapXepLuongTangDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getLuong() > ds[j].getLuong()) {
                cNhanVienVP temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}