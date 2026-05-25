#include "KhachThan.h"
#include <algorithm>
using namespace std;

void KhachThan::Nhap(istream &in) {
	KhachHang::Nhap(in);
	cout << "Nhap so nam than thiet: "; 
	in >> soNamThanThiet;
}
double KhachThan::ThanhTien() {
	double khuyenmai = max(soNamThanThiet * 0.05, 0.5);
	return (soLuong * donGia) * (1 - khuyenmai) * 1.1;
}

