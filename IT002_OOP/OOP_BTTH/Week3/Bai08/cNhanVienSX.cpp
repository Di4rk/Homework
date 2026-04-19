#define _CRT_SECURE_NO_WARNINGS

#include "cNhanVienSX.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

cNhanVienSX::cNhanVienSX() {
    maNV[0] = '\0';
    hoTen[0] = '\0';
    ngaySinh = 1;
    thangSinh = 1;
    namSinh = 1990;
    soSanPham = 0;
    donGia = 0;
}

cNhanVienSX::~cNhanVienSX() {}

float cNhanVienSX::tinhLuong() {
    return soSanPham * donGia;
}

int cNhanVienSX::getNamSinh() {
    return namSinh;
}

int cNhanVienSX::getThangSinh() {
    return thangSinh;
}

int cNhanVienSX::getNgaySinh() {
    return ngaySinh;
}

void cNhanVienSX::setMaNV(const char* ma) {
    strncpy(maNV, ma, 19);
    maNV[19] = '\0';
}

void cNhanVienSX::setHoTen(const char* ten) {
    strncpy(hoTen, ten, 49);
    hoTen[49] = '\0';
}

void cNhanVienSX::setNgaySinh(int d, int m, int y) {
    ngaySinh = d;
    thangSinh = m;
    namSinh = y;
}

void cNhanVienSX::setSoSanPham(int sp) {
    soSanPham = sp;
}

void cNhanVienSX::setDonGia(float gia) {
    donGia = gia;
}

void cNhanVienSX::nhap() {
    cout << "Nhap ma NV: ";
    cin >> ws;
    cin.getline(maNV, 20);

    cout << "Nhap ho ten: ";
    cin.getline(hoTen, 50);

    cout << "Nhap ngay thang nam sinh (vd: 15 8 2002): ";
    cin >> ngaySinh >> thangSinh >> namSinh;

    cout << "Nhap so san pham da gia cong: ";
    cin >> soSanPham;

    cout << "Nhap don gia mot san pham: ";
    cin >> donGia;
}

void cNhanVienSX::xuat() {
    cout << "Ma NV: " << maNV << " | Ten: " << hoTen
        << " | NS: " << ngaySinh << "/" << thangSinh << "/" << namSinh
        << " | So SP: " << soSanPham << " | Don gia: " << fixed << setprecision(0) << donGia
        << " | Luong: " << fixed << setprecision(0) << tinhLuong() << "\n";
}

cDSNhanVienSX::cDSNhanVienSX() {
    ds = nullptr;
    n = 0;
}

cDSNhanVienSX::~cDSNhanVienSX() {
    if (ds != nullptr) {
        delete[] ds;
    }
}

void cDSNhanVienSX::nhap() {
    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> n;

    if (ds != nullptr) {
        delete[] ds;
    }
    ds = new cNhanVienSX[n];

    for (int i = 0; i < n; i++) {
        cout << "--- Nhap nhan vien thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }
}

void cDSNhanVienSX::xuatDanhSach() {
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }
}

cNhanVienSX cDSNhanVienSX::timNhanVienLuongThapNhat() {
    if (n == 0) return cNhanVienSX();
    cNhanVienSX minLuong = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].tinhLuong() < minLuong.tinhLuong()) {
            minLuong = ds[i];
        }
    }
    return minLuong;
}

float cDSNhanVienSX::tinhTongLuong() {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].tinhLuong();
    }
    return tong;
}

cNhanVienSX cDSNhanVienSX::timNhanVienTuoiCaoNhat() {
    if (n == 0) return cNhanVienSX();
    cNhanVienSX oldest = ds[0];
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

void cDSNhanVienSX::sapXepLuongTangDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].tinhLuong() > ds[j].tinhLuong()) {
                cNhanVienSX temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}