#include <iostream>
#include <cmath>
#include "Tamgiac.h"
using namespace std;

int main() {
	cTamGiac tg;
	cout << "Tam giac khi chua khoi tao:\n" << tg;
	cout << "Nhap tam giac:\n";
	cin >> tg;
	cout << "Tam giac sau khi khoi tao:\n" << tg;

	cout << "\nKiem tra loai tam giac:\n";
	tg.KiemTra();

	cout << "\nChu vi tam giac: " << tg.ChuVi() << endl;
	cout << "\nDien tich tam giac: " << tg.DienTich() << endl;

	cout << "\nQuay tam giac 45 do:\n";
	cout << "Truoc khi quay:\n" << tg;
	tg.Quay(45);
	cout << "Sau khi quay:\n";
	cout << tg;

	cout << "\nTinh tien tam giac (dx=2, dy=3):\n";
	cout << "Truoc khi tinh tien:\n" << tg;
	tg.TinhTien(2, 3);
	cout << "Sau khi tinh tien:\n" << tg;

	cout << "\nPhong to tam giac (heso=2):\n";
	cout << "Truoc khi phong to:\n" << tg;
	tg.PhongTo(2);
	cout << "Sau khi phong to:\n" << tg;

	cout << "\nThu nho tam giac (heso=0.5):\n";
	cout << "Truoc khi thu nho:\n" << tg;
	tg.ThuNho(0.5);
	cout << "Sau khi thu nho:\n" << tg;
	return 0;
}