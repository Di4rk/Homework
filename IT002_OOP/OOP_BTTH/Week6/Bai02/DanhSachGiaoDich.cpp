#include "DanhSachGiaoDich.h"
#include "GiaoDichChungCu.h"
#include "GiaoDichDat.h"
#include "GiaoDichNhaPho.h"
using namespace std;

void DanhSachGiaoDich::Nhap() {
	int n;
	cout << "Nhap so luong giao dich: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "-----------------Giao dich thu " << i + 1 << ":\n";
		int loaiGiaoDich;
		cout << "Nhap loai giao dich (1: Giao Dich Dat, 2: Giao Dich Nha Pho, 3: Giao Dich Chung Cu): ";
		cin >> loaiGiaoDich;
		GiaoDich* gd;
		switch (loaiGiaoDich) {
		case 1:
			gd = new GiaoDichDat();
			break;
		case 2:
			gd = new GiaoDichNhaPho();
			break;
		case 3:
			gd = new GiaoDichChungCu();
			break;
		default:
			cout << "Loai giao dich khong hop le. Vui long nhap lai.\n"; 
			return;
		}

		gd->Nhap();
		ds.push_back(gd);
	}
}

void DanhSachGiaoDich::Xuat() {
	for (size_t i = 0; i < ds.size(); i++) {
		cout << "-----------------Giao dich thu " << i + 1 << ":\n";
		ds[i]->Xuat();
	}
}

int DanhSachGiaoDich::TongSoLuongTungLoai() {
	int countDat = 0, countNhaPho = 0, countChungCu = 0;
	for (auto x : ds) {
		if (dynamic_cast<GiaoDichDat*>(x)) {
			countDat++;
		}
		else if (dynamic_cast<GiaoDichChungCu*>(x)) {
			countChungCu++;
		}
		else if (dynamic_cast<GiaoDichNhaPho*>(x)) {
			countNhaPho++;
		}
	}

	cout << "So luong giao dich cua tung loai:\n";
	cout << "Giao dich dat: " << countDat << endl;
	cout << "Giao dich nha pho: " << countNhaPho << endl;
	cout << "Giao dich chung cu: " << countChungCu << endl;

	return countChungCu;
}

double DanhSachGiaoDich::averageThanhTienChungCu() {
	double tongThanhTienChungCu = 0;
	int count = 0;
	for (auto x : ds) {
		if (dynamic_cast<GiaoDichChungCu*>(x)) {
			count++;
			tongThanhTienChungCu += x->ThanhTien();
		}
	}
	if (count == 0) {
		return 0;
	}
	return tongThanhTienChungCu / count;
}

double DanhSachGiaoDich::maxValueGDNhaPho() {
	double maxValue = 0;
	GiaoDich* maxGiaoDich = nullptr;
	for (auto x : ds) {
		if (dynamic_cast<GiaoDichNhaPho*>(x)) {
			double thanhTien = x->ThanhTien();
			if (thanhTien > maxValue) {
				maxValue = thanhTien;
				maxGiaoDich = x;
			}
		}
	}
	if (maxGiaoDich == nullptr) {
		cout << "Khong co giao dich nha pho nao trong danh sach.\n";
		return 0;

	}
	else {
		cout << "Giao dich nha pho co thanh tien cao nhat:\n";
		maxGiaoDich->Xuat();
		return maxValue;
	}
}

void DanhSachGiaoDich::XuatGiaoDichThang12Nam2024() {
	cout << "Cac giao dich thang 12 nam 2024:\n";
	for (auto x : ds) {
		if (x->getDate()) {
			x->Xuat();
			cout << "------------------------------\n";
		}
	}
}

DanhSachGiaoDich::~DanhSachGiaoDich() {
	for (auto x : ds) {
		delete x;
	}
}