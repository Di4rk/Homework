#include "NVSanXuat.h"

void NVSanXuat::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap luong can ban: ";
    cin >> luongCanBan;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
}

void NVSanXuat::TinhLuong() {
    luong = luongCanBan + soSanPham * 5000;
}

void NVSanXuat::Xuat() {
    NhanVien::Xuat();
    cout << " | Loai: Nhan vien san xuat" << endl;
}