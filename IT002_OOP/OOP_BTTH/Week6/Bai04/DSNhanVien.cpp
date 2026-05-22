#include "DSNhanVien.h"
using namespace std;

void DSNhanVien::Nhap() {
	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int loai;
		cout << "Nhap loai nhan vien (1 - Lap trinh, 2 - Kiem chung): ";
		cin >> loai;
		NhanVien* nv;
		if (loai == 1) {
			nv = new LapTrinh();
		}
		else if (loai == 2) {
			nv = new KiemChung();
		}
		else {
			cout << "Loai nhan vien khong hop le. Bo qua. " << endl;
			continue;
		}
		nv->Nhap();
		ds.push_back(nv);
	}
	cout << "Nhap xong " << ds.size() << " nhan vien." << endl;
	cout << "---------------------------------------------" << endl;
}

void DSNhanVien::Xuat() {
	for (const auto& nv : ds) {
		nv->Xuat();
	}
	cout << "---------------------------------------------\n";
}

void DSNhanVien::NVDuoiTB() {
	double tongLuong = 0;
	int soluongnv = ds.size();
	if (soluongnv == 0) {
		cout << "Khong co nhan vien nao. " << endl;
		return;
	}

	for (const auto& x : ds) {
		tongLuong += x->Luong();
	}

	double luongTB = tongLuong / soluongnv;
	cout << "Luong trung binh: " << luongTB << endl;
	cout << "Danh sach nhan vien luong duoi trung binh: " << endl;
	for (const auto& x : ds) {
		if (x->Luong() < luongTB) {
			x->Xuat();
		}
	}
	cout << "---------------------------------------------\n";
}

void DSNhanVien::NVLuongCaoNhat() {
	if (ds.empty()) {
		cout << "Khong co nhan vien nao." << endl;
		return;
	}

	double maxLuong = ds[0]->Luong();
	NhanVien* nvMax = ds[0];
	for (const auto& x : ds) {
		if (x->Luong() > maxLuong) {
			maxLuong = x->Luong();
			nvMax = x;
		}
	}
	cout << "Nhan vien co luong cao nhat:\n";
	nvMax->Xuat();
	cout << "---------------------------------------------\n";
}

void DSNhanVien::NVLuongThapNhat() {
	if (ds.empty()) {
		cout << "Khong co nhan vien nao." << endl;
		return;
	}
	double minLuong = ds[0]->Luong();
	NhanVien* nvMin = ds[0];
	for (const auto& x : ds) {
		if (x->Luong() < minLuong) {
			minLuong = x->Luong();
			nvMin = x;
		}
	}
	cout << "Nhan vien co luong thap nhat:\n";
	nvMin->Xuat();
	cout << "---------------------------------------------\n";
}

void DSNhanVien::LapTrinhLuongCaoNhat() {
	vector<NhanVien*> lapTrinhVien;
	for (const auto& x : ds) {
		if (dynamic_cast<LapTrinh*>(x)) {
			lapTrinhVien.push_back(x);
		}
	}

	if (lapTrinhVien.empty()) {
		cout << "Khong co nhan vien lap trinh nao." << endl;
		return;
	}

	double maxLuong = lapTrinhVien[0]->Luong();
	NhanVien* nvMax = lapTrinhVien[0];
	for (const auto& x : lapTrinhVien) {
		if (x->Luong() > maxLuong) {
			maxLuong = x->Luong();
			nvMax = x;
		}
	}
	cout << "Nhan vien lap trinh co luong cao nhat:\n";
	nvMax->Xuat();
}

void DSNhanVien::KiemChungLuongThapNhat() {
	vector<NhanVien*> kiemChungVien;
	for (const auto& x : ds) {
		if (dynamic_cast<KiemChung*>(x)) {
			kiemChungVien.push_back(x);
		}
	}
	if (kiemChungVien.empty()) {
		cout << "Khong co nhan vien kiem chung nao." << endl;
		return;
	}
	double minLuong = kiemChungVien[0]->Luong();
	NhanVien* nvMin = kiemChungVien[0];
	for (const auto& x : kiemChungVien) {
		if (x->Luong() < minLuong) {
			minLuong = x->Luong();
			nvMin = x;
		}
	}
	cout << "Nhan vien kiem chung co luong thap nhat:\n";
	nvMin->Xuat();
}

DSNhanVien::~DSNhanVien() {
	for (auto& nv : ds) {
		delete nv;
	}
}
