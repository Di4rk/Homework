#include "GiaoDichVang.h"

void GiaoDichVang::Nhap() {
    GiaoDich::Nhap();
    cout << "Nhap loai vang: ";
    cin.ignore();
    getline(cin, loaiVang);
}

void GiaoDichVang::Xuat() {
    GiaoDich::Xuat();
    cout << " | Loai vang: " << loaiVang
        << " | Thanh tien: " << TinhThanhTien() << endl;
}

double GiaoDichVang::TinhThanhTien() {
    return soLuong * donGia;
}