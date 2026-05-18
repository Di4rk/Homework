#include "GDDat.h"

void GDDat::Nhap() {
    GiaoDichBDS::Nhap();
    cout << "Nhap loai dat (A, B, C): ";
    cin >> loaiDat;
}

void GDDat::Xuat() {
    GiaoDichBDS::Xuat();
    cout << " | Loai dat: " << loaiDat
        << " | Thanh tien: " << TinhThanhTien() << endl;
}

double GDDat::TinhThanhTien() {
    if (loaiDat == "A" || loaiDat == "a") {
        return dienTich * donGia * 1.5;
    }
    return dienTich * donGia;
}