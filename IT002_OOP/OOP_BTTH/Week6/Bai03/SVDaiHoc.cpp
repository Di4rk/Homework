#include "SVDaiHoc.h"
using namespace std;


void SVDaiHoc::Nhap() {
	SinhVien::Nhap();
	cin.ignore();
	cout << "Nhap ten luan van: ";
	getline(cin, tenLuanVan);
	cout << "Nhap diem luan van: ";
	cin >> diemLuanVan;
	cout << "------------------------------\n";
}

void SVDaiHoc::Xuat() {
	SinhVien::Xuat();
	cout << "| Ten luan van: " << tenLuanVan
		<< "| Diem luan van: " << diemLuanVan
		<< "------------------------------\n";
}

bool SVDaiHoc::TotNghiep() {
	return (tongSoTinChi >= 170 && diemTrungBinh >= 5 && diemLuanVan >= 5);
}