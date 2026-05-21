#include "GiaoDichDat.h"

using namespace std;

void GiaoDichDat::Nhap() {
	GiaoDich::Nhap();
	cin.ignore();
	cout << "Nhap loai dat (A, B, C): ";
	cin >> loaiDat;
	cout << "Nhap dien tich: ";
	cin >> DienTich;
	cout << "------------------------------\n";
}

void GiaoDichDat::Xuat() {
	GiaoDich::Xuat();
	cout << "Loai dat: " << loaiDat << endl;
	cout << "Dien tich: " << DienTich << endl;
}

double GiaoDichDat::ThanhTien() {
	double thanhTien = 0;
	if (loaiDat == 'A') {
		return DienTich * DonGia * 1.5;
	}
	else {
		return DienTich * DonGia;
	}
}