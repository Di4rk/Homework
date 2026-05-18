#include "NhanVien.h"

void NhanVien::Nhap() {
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);
}

void NhanVien::Xuat() {
    cout << "Ho ten: " << hoTen << " | Ngay sinh: " << ngaySinh
        << " | Luong: " << (long long)luong;
}

double NhanVien::getLuong() {
    return luong;
}