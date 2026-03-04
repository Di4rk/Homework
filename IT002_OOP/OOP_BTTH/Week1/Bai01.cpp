#include "PhanSo.h"
#include <iostream>
using namespace std; 
PhanSo::PhanSo() {
	tu = 0;
	mau = 1;
}
PhanSo::PhanSo(int tu, int mau) {
	this->tu = tu;
	this->mau = mau;
}
void PhanSo::Nhap() {
	cout << "Nhap tu: ";
	cin >> tu;
	cout << "Nhap mau: ";
	cin >> mau;
}
void PhanSo::Xuat() {
	cout << tu << "/" << mau;
}
int PhanSo::UCLN(int a, int b) {
	if (b == 0) return a;
	return UCLn(b, a % b);
}
void PhanSo::RutGon() {
	int ucln = UCLN(tu, mau);
	tu /= ucln;
	mau /= ucln;
}