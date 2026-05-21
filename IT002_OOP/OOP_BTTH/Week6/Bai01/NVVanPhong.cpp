#include "NVVanPhong.h"
using namespace std;

void NVVanPhong::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so ngay lam viec: ";
	cin >> SoNgayLamViec;
}

void NVVanPhong::Xuat() {
	NhanVien::Xuat();
	cout << "So ngay lam viec: " << SoNgayLamViec << endl;
}

NVVanPhong::~NVVanPhong() {}

long long NVVanPhong::TinhLuong() {
	return SoNgayLamViec * 100000;
}