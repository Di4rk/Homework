#include "GiaoDichTienTe.h"

void GiaoDichTienTe::Nhap() {
    GiaoDich::Nhap();
    cout << "Nhap loai tien (1: VN, 2: USD, 3: Euro): ";
    cin >> loaiTien;
    if (loaiTien == 2 || loaiTien == 3) {
        cout << "Nhap ti gia: ";
        cin >> tiGia;
    }
    else {
        tiGia = 1;
    }
}

void GiaoDichTienTe::Xuat() {
    GiaoDich::Xuat();
    string tenLoai = (loaiTien == 1) ? "VN" : (loaiTien == 2) ? "USD" : "Euro";
    cout << " | Loai tien: " << tenLoai
        << " | Ti gia: " << tiGia
        << " | Thanh tien: " << TinhThanhTien() << endl;
}

double GiaoDichTienTe::TinhThanhTien() {
    if (loaiTien == 1) {
        return soLuong * donGia;
    }
    return soLuong * donGia * tiGia;
}

int GiaoDichTienTe::getLoaiTien() {
    return loaiTien;
}