#include "NhanVien.h"

NhanVien::~NhanVien() {}

NhanVien::Nhap() {
	cin.ignore();
	cout << "Nhap ho ten: ";
	getline(cin, HoTen);
	cout << "Nhap ngay sinh (dd mm yyyy): ";
	cin >> NgaySinh.day >> NgaySinh.month >> NgaySinh.year;
}

NhanVien::Xuat() {
	cout << "Ho Ten: " << HoTen << "| Ngay Sinh: " << NgaySinh.day << "/" << NgaySinh.month << "/" << NgaySinh.year << endl;
}