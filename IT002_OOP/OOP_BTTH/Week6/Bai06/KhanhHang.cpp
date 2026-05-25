#include "KhachHang.h"

using namespace std;

void KhachHang::Nhap(istream &in) {
	in.ignore();
	cout << "Nhap ten khach hang: ";
	getline(in, TenKH);
	cout << "Nhap so luong hang: ";
	in >> soLuong;
	cout << "Nhap don gia hang: ";
	in >> donGia;
}

void KhachHang::Xuat(ostream &out) {
	out << "Ten Khach: " << TenKH << endl;
	out << "So tien phai tra: " << ThanhTien() << endl;
	cout << "-----------------------------" << endl; 
}

KhachHang::~KhachHang() {}