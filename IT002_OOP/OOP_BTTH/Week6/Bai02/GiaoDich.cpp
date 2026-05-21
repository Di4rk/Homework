#include "GiaoDich.h"
using namespace std;

void GiaoDich::Nhap() {
	cin.ignore();
	cout << "Nhap ma giao dich: ";
	getline(cin, maGiaoDich);

	cout << "Nhap ngay giao dich (dd mm yyyy): ";
	cout << "Ngay: ";
	cin >> ngayGiaoDich.day;
	cout << "Thang: ";
	cin >> ngayGiaoDich.month;
	cout << "Nam: ";
	cin >> ngayGiaoDich.year;

	cout << "Nhap don gia: ";
	cin >> DonGia;
}

void GiaoDich::Xuat() {
	cout << "Ma giao dich: " << maGiaoDich << endl;
	cout << "Ngay giao dich: " << ngayGiaoDich.day << "/" << ngayGiaoDich.month << "/" << ngayGiaoDich.year << endl;
	cout << "Don gia: " << DonGia << endl;
}

bool GiaoDich::getDate() {
	if (ngayGiaoDich.month == 12 && ngayGiaoDich.year == 2024) {
		return true;
	}
	return false;
}

GiaoDich::~GiaoDich() {}