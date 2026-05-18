#include "NVVanPhong.h"

void NVVanPhong::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLamViec;
}

void NVVanPhong::TinhLuong() {
    luong = soNgayLamViec * 100000;
}

void NVVanPhong::Xuat() {
    NhanVien::Xuat();
    cout << " | Loai: Nhan vien van phong" << endl;
}