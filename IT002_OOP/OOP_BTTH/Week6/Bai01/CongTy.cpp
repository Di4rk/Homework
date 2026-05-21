#include "CongTy.h"
#include "NVSanXuat.h"
#include "NVVanPhong.h"
#include <climits>
using namespace std;

DanhSachNhanVien::~DanhSachNhanVien() {
	for (auto x : ds) {
		delete x;
	}
}

void DanhSachNhanVien::Nhap() {
	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int loai;
		cout << "Nhap loai nhan vien (1: NVSanXuat, 2: NVVanPhong): ";
		cin >> loai;
		NhanVien* nv;
		if (loai == 1) {
			nv = new NVSanXuat();
		}
		else {
			nv = new NVVanPhong();
		}
		if (nv != nullptr) {
			nv->Nhap();
			ds.push_back(nv);
		}
	}
}

void DanhSachNhanVien::Xuat() {
	for (auto x : ds) {
		x->Xuat();
		cout << "Tien luong: " << x->TinhLuong() << "VND\n";
		cout << "-----------------------------\n";
	}
}


long long DanhSachNhanVien::TongLuong() {
	long long tong = 0;
	for (auto x : ds) {
		tong += x->TinhLuong();
	}
	return tong;
}

void DanhSachNhanVien::LuongThapNhat() {
	long long minLuong = LLONG_MAX;
	NhanVien* nvMin = nullptr;
	for (auto x : ds) {
		NVSanXuat* sv = dynamic_cast<NVSanXuat*>(x);
		if (sv != nullptr) {
			long long luong = sv->TinhLuong();
			if (luong < minLuong) {
				minLuong = luong;
				nvMin = x;	
			}
		}
	}

	if (nvMin != nullptr) {
		cout << "Nhan vien san xuat co luong thap nhat: " << endl;
		nvMin->Xuat();
	}
	else {
		cout << "Khong co nhan vien nao: " << endl;
	}
}

void DanhSachNhanVien::TuoiCaoNhat() {
	int maxTuoi = -1;
	NhanVien* nvMax = nullptr;
	for (auto x : ds) {
		NVVanPhong *vp = dynamic_cast<NVVanPhong*>(x);
		if (vp != nullptr) {
			int tuoi = vp->GetTuoi();
			if (tuoi < maxTuoi) {
				maxTuoi = tuoi;
				nvMax = x;
			}
		}
	}
	if (nvMax != nullptr) {
		cout << "\nNhan vien van phong co tuoi cao nhat: " << endl;
		nvMax->Xuat();
	}
	else {
		cout << "Khong co nhan vien van phong nao: " << endl;
	}
	
}