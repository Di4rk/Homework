#include "NVSanXuat.h"
using namespace std;
NVSanXuat::~NVSanXuat() {}

void NVSanXuat::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap luong can ban: ";
	cin >> LuongCanBan;
	cout << "Nhap so san pham: ";
	cin >> SoSanPham;
}

void NVSanXuat::Xuat() {
	NhanVien::Xuat();
	cout << "Luong can ban: " << LuongCanBan << "| So san pham: " << SoSanPham << endl;
}

long long NVSanXuat::TinhLuong() {
	return LuongCanBan + SoSanPham * 5000;
}

