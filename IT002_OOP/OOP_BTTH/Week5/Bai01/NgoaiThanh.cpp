#include "NgoaiThanh.h"

void NgoaiThanh::Nhap() {
    ChuyenXe::Nhap();
    cout << "Nhap noi den: ";
    cin.ignore();
    getline(cin, noiDen);
    cout << "Nhap so ngay di duoc: ";
    cin >> soNgay;
}

void NgoaiThanh::Xuat() {
    ChuyenXe::Xuat();
    cout << " | Noi den: " << noiDen << " | So ngay: " << soNgay << endl;
}