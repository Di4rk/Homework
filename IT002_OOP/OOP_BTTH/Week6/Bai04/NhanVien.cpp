#include "NhanVien.h"
using namespace std;

void NhanVien::Nhap() {
	cin.ignore();
	cout << "Nhap ma nhan vien: ";
	getline(cin, maNV);
	cout << "Nhap ho ten: ";
	getline(cin, hoTen);
	cout << "Nhap so dien thoai: ";
	getline(cin, soDT);
	cout << "Nhap email: ";
	getline(cin, email);
	cout << "Nhap tuoi: ";
	cin >> tuoi;
	cout << "Nhap luong co ban: ";
	cin >> luongCoBan;
}

void NhanVien::Xuat() {
	cout << "Ma nhan vien: " << maNV
		<< "| Ho ten: " << hoTen
		<< "| So dien thoai: " << soDT
		<< "| Email: " << email
		<< "| Tuoi: " << tuoi
		<< "| Luong co ban: " << luongCoBan;
}

NhanVien::~NhanVien() {}
