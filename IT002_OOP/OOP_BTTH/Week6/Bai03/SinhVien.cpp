#include "SinhVien.h"
using namespace std;
void SinhVien::Nhap() {
	cin.ignore();
	cout << "Nhap ma sinh vien: ";
	getline(cin, maSV);
	cout << "Nhap ho ten: ";
	getline(cin, hoTen);
	cout << "Nhap tong so tin chi: ";
	cin >> tongSoTinChi;
	cout << "Nhap diem trung binh: ";
	cin >> diemTrungBinh;
}

void SinhVien::Xuat() {
	cout << "Ma SV: " << maSV
		<< "| Ho ten: " << hoTen
		<< "| Tong so tin chi: " << tongSoTinChi
		<< "| Diem trung binh: " << diemTrungBinh << endl;
}

float SinhVien::getDiemTrungBinh() const {
	return diemTrungBinh;
}
SinhVien::~SinhVien() {}