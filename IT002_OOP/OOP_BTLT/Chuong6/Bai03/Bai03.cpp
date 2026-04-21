#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NV {
protected:
	string maNV, hoTen, email;
	int Tuoi, luongCoban;
	string soDienThoai;
public:
	NV() : maNV(""), hoTen(""), email(""), Tuoi(0), soDienThoai(""), luongCoban(0) {}
	virtual void Nhap() {
		cin.ignore();
		cout << "Nhap ma NV: ";
		getline(cin, maNV);
		cout << "Nhap ho ten: ";
		getline(cin, hoTen);
		cout << "Nhap tuoi: ";
		cin >> Tuoi;
		cout << "Nhap so dien thoai: ";
		getline(cin, soDienThoai);
		cout << "Nhap email: ";
		getline(cin, email);
		cout << "Nhap luong co ban: ";
		cin >> luongCoban;
	}

	virtual void Xuat() const {
		cout << "Ma NV: " << maNV << " | Ho ten: " << hoTen
			<< " | Tuoi: " << Tuoi
			<< " | So dien thoai: " << soDienThoai
			<< " | Email: " << email
			<< " | Luong co ban: " << luongCoban;
	}

	virtual double TinhLuong() const = 0;

	virtual ~NV() {}
};

class NVLapTrinh : public NV {
private:
	int soGioovertime;
public:
	void Nhap() override {
		cout << "Nhap thong tin NV Lap Trinh: \n";
		NV::Nhap();
		cout << "Nhap so gio overtime: ";
		cin >> soGioovertime;
	}

	void Xuat() const override {
		cout << "Nhan vien Lap Trinh: \n";
		NV::Xuat();
		cout << " | So gio overtime: " << soGioovertime
			<< " | Luong: " << static_cast<long long>(TinhLuong()) << endl;
	}

	double TinhLuong() const override {
		return luongCoban + (soGioovertime * 200000);
	}
};

class NVKiemChung : public NV {
private: 
	int soLoiPhatHien;
public:
	void Nhap() override {
		cout << "Nhap thong tin NV Kiem Chung: \n";
		NV::Nhap();
		cout << "Nhap so loi phat hien: ";
		cin >> soLoiPhatHien;
	}
	void Xuat() const override {
		cout << "Nhan vien Kiem Chung: \n";
		NV::Xuat();
		cout << " | So loi phat hien: " << soLoiPhatHien
			<< " | Luong: " << static_cast<long long>(TinhLuong()) << endl;
	}
	double TinhLuong() const override {
		return luongCoban + (soLoiPhatHien * 50000);
	}
};

int main() {
	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	vector<NV*> danhsachNV;
	while (n--) {
		int loaiNV;
		cout << "Nhap loai NV (1 - lap trinh, 2 - kiem chung): ";
		cin >> loaiNV;
		if (loaiNV == 1) {
			danhsachNV.push_back(new NVLapTrinh());
			danhsachNV.back()->Nhap();
		}
		else if (loaiNV == 2) {
			danhsachNV.push_back(new NVKiemChung());
			danhsachNV.back()->Nhap();
		}
		else {
			cout << "Loai NV khong hop le. Vui long nhap lai." << endl;
			n++;
		}
	}

	cout << "\n=== DANH SACH NHAN VIEN CONG TY ===" << endl;
	double tongLuong = 0;
	for (const auto& nv : danhsachNV) {
		nv->Xuat();
		tongLuong += nv->TinhLuong();
	}

	double luongTrungBinh = tongLuong / danhsachNV.size();
	cout << "\n=> LUONG TRUNG BINH CUA CONG TY: " << static_cast<long long>(luongTrungBinh) << " VND\n";

	cout << "\n=== DANH SACH NV CO LUONG THAP HON MUC TRUNG BINH ===" << endl;
	bool coNhanVienNgheo = false;
	for (const auto& nv : danhsachNV) {
		if (nv->TinhLuong() < luongTrungBinh) {
			nv->Xuat();
			coNhanVienNgheo = true;
		}
	}

	if (!coNhanVienNgheo) {
		cout << "Khong co ai co luong thap hon muc trung binh!" << endl;
	}

	for (size_t i = 0; i < danhsachNV.size(); ++i) {
		delete danhsachNV[i];
	}
	danhsachNV.clear();

	return 0;
}