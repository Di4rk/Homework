#include "GDChungCu.h"

void GDChungCu::Nhap() {
    GiaoDichBDS::Nhap();
    cout << "Nhap ma can: ";
    cin >> maCan;
    cout << "Nhap vi tri tang: ";
    cin >> viTriTang;
}

void GDChungCu::Xuat() {
    GiaoDichBDS::Xuat();
    cout << " | Ma can: " << maCan
        << " | Tang: " << viTriTang
        << " | Thanh tien: " << TinhThanhTien() << endl;
}

double GDChungCu::TinhThanhTien() {
    if (viTriTang == 1) {
        return dienTich * donGia * 2;
    }
    else if (viTriTang >= 15) {
        return dienTich * donGia * 1.2;
    }
    return dienTich * donGia;
}