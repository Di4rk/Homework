#include "SVCaoDang.h"

void SVCaoDang::Nhap() {
	SinhVien::Nhap();
	cout << "Nhap diem thi tot nghiep: ";
	cin >> diemThiTotNghiep;
	cout << "------------------------------\n";
}

void SVCaoDang::Xuat() {
	SinhVien::Xuat();
	cout << "| Diem thi tot nghiep: " << diemThiTotNghiep
		<< "------------------------------\n";
}

bool SVCaoDang::TotNghiep() {
	return (tongSoTinChi >= 120 && diemTrungBinh >= 5 && diemThiTotNghiep >= 5);
}

