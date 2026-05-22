#include "LapTrinh.h"
using namespace std;

void LapTrinh::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so gio overtime: ";
	cin >> soGioOvertime;
}

void LapTrinh::Xuat() {
	NhanVien::Xuat();
	cout << "| So gio overtime: " << soGioOvertime;
	cout << "| Luong: " << Luong() << endl;
}

double LapTrinh::Luong() {
	return luongCoBan + soGioOvertime * 200000;
}