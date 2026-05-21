#include <iostream>
#include "DanhSachGiaoDich.h"
using namespace std;

int main() {
	DanhSachGiaoDich ds;
	ds.Nhap();
	ds.TongSoLuongTungLoai();

	double avr = ds.averageThanhTienChungCu();
	if (avr > 0) {
		cout << "Gia tri trung binh thanh tien cua giao dich chung cu: " << avr << endl;
	}
	else {
		cout << "Khong co giao dich chung cu nao.\n";
	}

	ds.maxValueGDNhaPho();
	ds.XuatGiaoDichThang12Nam2024();
}