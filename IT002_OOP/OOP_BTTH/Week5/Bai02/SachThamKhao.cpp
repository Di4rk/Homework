#include "SachThamKhao.h"

void SachThamKhao::Nhap() {
    Sach::Nhap();
    cout << "Nhap thue: ";
    cin >> thue;
}

void SachThamKhao::Xuat() {
    Sach::Xuat();
    cout << " | Thue: " << thue
        << " | Thanh tien: " << TinhThanhTien() << endl;
}

double SachThamKhao::TinhThanhTien() {
    return soLuong * donGia + thue;
}