#include "GDNhaPho.h"

void GDNhaPho::Nhap() {
    GiaoDichBDS::Nhap();
    cout << "Nhap dia chi: ";
    cin.ignore();
    getline(cin, diaChi);
    cout << "Nhap loai nha (1: Cao cap, 2: Thuong): ";
    cin >> loaiNha;
}

void GDNhaPho::Xuat() {
    GiaoDichBDS::Xuat();
    cout << " | Dia chi: " << diaChi
        << " | Loai nha: " << (loaiNha == 1 ? "Cao cap" : "Thuong")
        << " | Thanh tien: " << TinhThanhTien() << endl;
}

double GDNhaPho::TinhThanhTien() {
    if (loaiNha == 1) {
        return dienTich * donGia;
    }
    return dienTich * donGia * 0.9;
}