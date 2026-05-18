#include "NoiThanh.h"

void NoiThanh::Nhap() {
    ChuyenXe::Nhap();
    cout << "Nhap so tuyen: ";
    cin >> soTuyen;
    cout << "Nhap so km di duoc: ";
    cin >> soKm;
}

void NoiThanh::Xuat() {
    ChuyenXe::Xuat();
    cout << " | So tuyen: " << soTuyen << " | So km: " << soKm << endl;
}