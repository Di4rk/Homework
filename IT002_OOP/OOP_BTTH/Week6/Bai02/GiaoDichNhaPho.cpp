#include "GiaoDichNhaPho.h"
using namespace std;

void GiaoDichNhaPho::Nhap() {
	GiaoDich::Nhap();
	cin.ignore();
	cout << "Nhap loai nha (1: 'Cao Cap', 2: 'Thuong'): ";
	cin >> loaiNha;
	cin.ignore();
	cout << "Nhap dia chi: ";
	getline(cin, diaChi);
	cout << "Nhap dien tich: ";
	cin >> DienTich;
	cout << "------------------------------\n";
}

void GiaoDichNhaPho::Xuat() {
	GiaoDich::Xuat();
	cout << "Loai nha: " << (loaiNha == 1 ? "Cao Cap" : "Thuong") << endl;
	cout << "Dia chi: " << diaChi << endl;
	cout << "Dien tich: " << DienTich << endl;
}

double GiaoDichNhaPho::ThanhTien() {
	double thanhTien = 0;
	if (loaiNha == 1) {
		return DienTich * DonGia;
	}
	else {
		return DienTich * DonGia * 0.9;
	}
}