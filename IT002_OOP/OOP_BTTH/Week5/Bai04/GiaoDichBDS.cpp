#include "GiaoDichBDS.h"

void GiaoDichBDS::Nhap() {
    cout << "Nhap ma giao dich: ";
    cin >> maGD;
    cout << "Nhap ngay giao dich (dd/mm/yyyy): ";
    cin >> ngayGD;
    cout << "Nhap don gia: ";
    cin >> donGia;
    cout << "Nhap dien tich: ";
    cin >> dienTich;
}

void GiaoDichBDS::Xuat() {
    cout << "Ma GD: " << maGD << " | Ngay: " << ngayGD
        << " | Don gia: " << donGia << " | Dien tich: " << dienTich;
}

string GiaoDichBDS::getNgayGD() {
    return ngayGD;
}