#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class CBVD {
protected:
	string maCB;
	string hoTen;
	string gioiTinh;

public:
	CBVD() : maCB(""), hoTen(""), gioiTinh("") {}

	virtual void nhap() {
		cin.ignore();
		cout << "Nhap ma Can bo: ";
		getline(cin, maCB);
		cout << "Nhap ho ten: ";
		getline(cin, hoTen);
		cout << "Nhap gioi tinh: ";
		getline(cin, gioiTinh);
	}

	virtual void xuat() const {
		cout << "Ma CB: " << maCB
			<< " | Ho ten: " << hoTen
			<< " | Gioi Tinh: " << gioiTinh;
	}

	virtual double tinhLuong() const = 0;

	virtual ~CBVD() {}
};

class GiangVien : public CBVD {
private:
	int soGioDay;
	int soGioNghienCuu;
	const double DON_GIA = 150000;

public:
	void nhap() override {
		cout << "\n--- Nhap thong tin Giang Vien ---" << endl;
		CBVD::nhap();
		cout << "Nhap so gio day: ";
		cin >> soGioDay;
		cout << "Nhap so gio nghien cuu: ";
		cin >> soGioNghienCuu;
	}

	void xuat() const override {
		CBVD::xuat();
		cout << " | So gio day: " << soGioDay
			<< " | So gio NC: " << soGioNghienCuu
			<< " | Luong: " << static_cast<long long>(tinhLuong()) << endl;
	}

	double tinhLuong() const override {
		return (soGioDay + soGioNghienCuu) * DON_GIA;
	}
};

class NhanVienHanhChinh : public CBVD {
private:
	int soNgayLamViec;
	int soGioLamThem;
	const double TIEN_CONG_NGAY = 300000;
	const double TIEN_CONG_GIO = 50000;

public:
	void nhap() override {
		cout << "\n--- Nhap thong tin Nhan Vien Hanh Chinh ---" << endl;
		CBVD::nhap();
		cout << "Nhap so ngay lam viec: ";
		cin >> soNgayLamViec;
		cout << "Nhap so gio lam them: ";
		cin >> soGioLamThem;
	}

	void xuat() const override {
		CBVD::xuat();
		cout << " | So ngay lam: " << soNgayLamViec
			<< " | So gio lam them: " << soGioLamThem
			<< " | Luong: " << static_cast<long long>(tinhLuong()) << endl;
	}

	double tinhLuong() const override {
		return (soNgayLamViec * TIEN_CONG_NGAY) + (soGioLamThem * TIEN_CONG_GIO);
	}
};

int main() {
	vector<CBVD*> danhSachCBVC;
	int luachon;

	do {
		cout << "\n=== Quan ly can bo vien chuc ===" << endl;
		cout << "1. Them Giang Vien" << endl;
		cout << "2. Them Nhan Vien Hanh Chinh" << endl;
		cout << "3. Xuat danh sach va luong" << endl;
		cout << "0. Thoat" << endl;
		cout << "Chon chuc nang: ";
		cin >> luachon;

		CBVD* cbvc = nullptr;

		switch (luachon) {
		case 1:
			cbvc = new GiangVien();
			cbvc->nhap();
			danhSachCBVC.push_back(cbvc);
			break;
		case 2:
			cbvc = new NhanVienHanhChinh();
			cbvc->nhap();
			danhSachCBVC.push_back(cbvc);
			break;
		case 3:
			cout << "\n=== Danh sach Can bo Vien chuc ===" << endl;
			for (const auto& cb : danhSachCBVC) {
				cb->xuat();
			}
			break;
		case 0:
			cout << "Thoat chuong trinh." << endl;
			break;
		default:
			cout << "Lua chon khong hop le. Vui long chon lai." << endl;
		}
	} while (luachon != 0); 

	for (size_t i = 0; i < danhSachCBVC.size(); ++i) {
		delete danhSachCBVC[i];
	}
	danhSachCBVC.clear();

	return 0;
}