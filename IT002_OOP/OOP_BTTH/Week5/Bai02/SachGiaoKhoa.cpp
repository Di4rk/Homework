#include "SachGiaoKhoa.h"

void SachGiaoKhoa::Nhap() {
    Sach::Nhap();
    cout << "Nhap tinh trang (1: Moi, 2: Cu): ";
    cin >> tinhTrang;
}

void SachGiaoKhoa::Xuat() {
    Sach::Xuat();
    cout << " | Tinh trang: " << (tinhTrang == 1 ? "Moi" : "Cu")
        << " | Thanh tien: " << TinhThanhTien() << endl;
}

double SachGiaoKhoa::TinhThanhTien() {
    if (tinhTrang == 1) {
        return soLuong * donGia;
    }
    return soLuong * donGia * 0.5;
}