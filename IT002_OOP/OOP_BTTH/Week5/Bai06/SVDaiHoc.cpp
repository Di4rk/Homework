#include "SVDaiHoc.h"

void SVDaiHoc::Nhap() {
    SinhVien::Nhap();
    cout << "Nhap ten luan van: ";
    cin.ignore();
    getline(cin, tenLuanVan);
    cout << "Nhap diem luan van: ";
    cin >> diemLuanVan;
}

void SVDaiHoc::Xuat() {
    SinhVien::Xuat();
    cout << " | Luan van: " << tenLuanVan << " | Diem LV: " << diemLuanVan << " | He: Dai Hoc" << endl;
}

bool SVDaiHoc::XetTotNghiep() {
    return (tongTinChi >= 145 && diemTB >= 5.0 && diemLuanVan >= 5.0);
}