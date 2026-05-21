#include "NhanVien.h"
using namespace std;

NhanVien::~NhanVien() {}

void NhanVien::Nhap() {
	cin.ignore();
	cout << "Nhap ho ten: ";
	getline(cin, HoTen);
	cout << "Nhap ngay sinh (dd mm yyyy): ";
	cin >> NgaySinh.day >> NgaySinh.month >> NgaySinh.year;
}

void NhanVien::Xuat() {
	cout << "Ho Ten: " << HoTen << "| Ngay Sinh: " << NgaySinh.day << "/" << NgaySinh.month << "/" << NgaySinh.year << endl;
}

int NhanVien::GetTuoi() {
	return NgaySinh.day + NgaySinh.month * 30 + NgaySinh.year * 365;
}