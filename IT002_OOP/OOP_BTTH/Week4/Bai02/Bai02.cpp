#include "PhanSo.h"

int main() {
	PhanSo ps1, ps2;
	cout << "Nhap phan so 1 (tu mau): ";
	cin >> ps1;
	cout << "Nhap phan so 2 (tu mau): ";
	cin >> ps2;
	cout << "Phan so 1: " << ps1 << endl;
	cout << "Phan so 2: " << ps2 << endl;
	cout << "Tong: " << ps1 + ps2 << endl;
	cout << "Hieu: " << ps1 - ps2 << endl;
	cout << "Tich: " << ps1 * ps2 << endl;
	cout << "Thuong: " << ps1 / ps2 << endl;
	return 0;
}