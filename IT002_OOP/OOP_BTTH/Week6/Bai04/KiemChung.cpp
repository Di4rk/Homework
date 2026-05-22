#include "KiemChung.h"
using namespace std;

void KiemChung::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so loi phat hien: ";
	cin >> soLoiPhatHien;
}

void KiemChung::Xuat() {
	NhanVien::Xuat();
	cout << "| So loi phat hien: " << soLoiPhatHien;
	cout << "| Luong: " << Luong() << endl;
}

double KiemChung::Luong() {
	return luongCoBan + soLoiPhatHien * 50000;
}