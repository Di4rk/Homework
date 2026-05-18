#include "Sach.h"

void Sach::Nhap() {
    cout << "Nhap ma sach: ";
    cin >> maSach;
    cout << "Nhap ngay nhap: ";
    cin >> ngayNhap;
    cout << "Nhap don gia: ";
    cin >> donGia;
    cout << "Nhap so luong: ";
    cin >> soLuong;
    cout << "Nhap nha xuat ban: ";
    cin.ignore();
    getline(cin, nxb);
}

void Sach::Xuat() {
    cout << "Ma: " << maSach << " | Ngay: " << ngayNhap
        << " | Gia: " << donGia << " | SL: " << soLuong
        << " | NXB: " << nxb;
}

string Sach::getNxb() {
    return nxb;
}

double Sach::getDonGia() {
    return donGia;
}