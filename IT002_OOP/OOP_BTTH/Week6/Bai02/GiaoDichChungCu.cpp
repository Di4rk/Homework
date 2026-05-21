#include "GiaoDichChungCu.h"
using namespace std;

void GiaoDichChungCu::Nhap() {
	GiaoDich::Nhap();
	cin.ignore();
	cout << "Nhap ma can: ";
	getline(cin, maCan);
	cout << "Nhap vi tri tang: ";
	cin >> viTriTang;
	cout << "Nhap dien tich: ";
	cin >> DienTich;
	cout << "------------------------------\n";
}

void GiaoDichChungCu::Xuat() {
	GiaoDich::Xuat();
	cout << "Ma can: " << maCan << endl;
	cout << "Vi tri tang: " << viTriTang << endl;
	cout << "Dien tich: " << DienTich << endl;
}

double GiaoDichChungCu::ThanhTien() {
	if (viTriTang == 1) {
		return DienTich * DonGia * 2;
	}
	else if (viTriTang >= 15) {
		return DienTich * DonGia * 1.2;
	}
	else return DienTich * DonGia;
}