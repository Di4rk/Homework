#include "DanhSachSV.h"
using namespace std;

void DanhSachSV::Nhap() {
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int loai;
		cout << "Nhap loai sinh vien (1 - Dai hoc, 2 - Cao dang): ";
		cin >> loai;
		SinhVien* sv;
		if (loai == 1) {
			sv = new SVDaiHoc();
		}
		else if (loai == 2) {
			sv = new SVCaoDang();
		}
		else {
			cout << "Loai sinh vien khong hop le. Bo qua.\n";
			continue; 
		}
		if (sv != nullptr) {
			sv->Nhap();
			ds.push_back(sv);
			cout << "------------------------------\n";
		}
	}
}

void DanhSachSV::Xuat() {
	for (const auto& sv : ds) {
		sv->Xuat();
	}
}

void DanhSachSV::XuatSVTotNghiep() {
	cout << "Danh sach sinh vien tot nghiep: \n";
	for (const auto& sv : ds) {
		if (sv->TotNghiep()) {
			sv->Xuat();
		}
	}
	cout << "------------------------------\n";
}

void DanhSachSV::XuatSVKoTotNghiep() {
	cout << "Danh sach sinh vien khong tot nghiep: \n";
	for (const auto& sv : ds) {
		if (!sv->TotNghiep()) {
			sv->Xuat();
		}
	}
	cout << "------------------------------\n";
}

SinhVien* DanhSachSV::SVDaiHocCoDiemTrungBinhCaoNhat() {
	SinhVien* svMax = nullptr;
	for (const auto& sv : ds) {
		if (dynamic_cast<SVDaiHoc*>(sv)) {
			if (svMax == nullptr || sv->getDiemTrungBinh() > svMax->getDiemTrungBinh()) {
				svMax = sv;
			}
		}
	}
	return svMax;
}

SinhVien* DanhSachSV::SVCaoDangCoDiemTrungBinhCaoNhat() {
	SinhVien* svMax = nullptr;
	for (const auto& sv : ds) {
		if (dynamic_cast<SVCaoDang*>(sv)) {
			if (svMax == nullptr || sv->getDiemTrungBinh() > svMax->getDiemTrungBinh())
				svMax = sv;
		}
	}
	return svMax;
}

void DanhSachSV::SoLuongSVKoTotNghiepTheoLoai() {
	int countDH = 0, countCD = 0;
	cout << "So luong sinh vien khong tot nghiep theo loai: \n";
	for (const auto& sv : ds) {
		if (!sv->TotNghiep()) {
			if (dynamic_cast<SVDaiHoc*>(sv)) {
				++countDH;
			}
			else if (dynamic_cast<SVCaoDang*>(sv)) {
				++countCD;
			}
		}
	}
	cout << " - Dai hoc: " << countDH << endl;
	cout << " - Cao dang: " << countCD << endl;
}

DanhSachSV::~DanhSachSV() {
	for (auto& sv : ds) {
		delete sv;
	}
}