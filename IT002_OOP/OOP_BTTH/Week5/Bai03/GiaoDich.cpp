#include "GiaoDich.h"

void GiaoDich::Nhap() {
    cout << "Nhap ma giao dich: ";
    cin >> maGD;
    cout << "Nhap ngay giao dich (dd/mm/yyyy): ";
    cin >> ngayGD;
    cout << "Nhap don gia: ";
    cin >> donGia;
    cout << "Nhap so luong: ";
    cin >> soLuong;
}

void GiaoDich::Xuat() {
    cout << "Ma GD: " << maGD << " | Ngay: " << ngayGD
        << " | Don gia: " << donGia << " | SL: " << soLuong;
}