#include <iostream>
#include <string>
using namespace std;

class SV {
protected:
	string maSV;
	string hoTen;
	string diaChi;
	int SoTinChi;
	float diemTB;
public:
	SV() : maSV(""), hoTen(""), diaChi(""), SoTinChi(0), diemTB(0.0) {}
	virtual void Nhap() {
		cin.ignore();
		cout << "Nhap MSSV: ";
		getline(cin, maSV);
		cout << "Nhap ho ten: ";
		getline(cin, hoTen);
		cout << "Nhap dia chi: ";
		getline(cin, diaChi);
		cout << "Nhap so tin chi: ";
		cin >> SoTinChi;
		cout << "Nhap diem trung binh: ";
		cin >> diemTB;
	}

	virtual void Xuat() const {
		cout << "MSSV: " << maSV << " | Ho ten: " << hoTen
			<< " | Dia chi: " << diaChi
			<< " | So tin chi: " << SoTinChi
			<< " | Diem TB: " << diemTB;
	}

	virtual bool KiemTraTotNghiep() const = 0;

	virtual ~SV() {}
};

class SVCaoDang : public SV {
private:
	float DiemThiTotNghiep;
public:
	void Nhap() override {
		cout << "Nhap thong tin sinh ven cao dang: " << endl;
		SV::Nhap();
		cout << "Nhap diem thi tot nghiep: ";
		cin >> DiemThiTotNghiep;
	}

	void Xuat() const override {
		cout << "Sinh vien cao dang: " << endl;
		SV::Xuat();
		cout << " | Diem thi tot nghiep" << DiemThiTotNghiep << endl;
	}

	bool KiemTraTotNghiep() const override {
		return (SoTinChi >= 120 && diemTB >= 5.0 && DiemThiTotNghiep >= 5.0);
	}
};

class SVDaiHoc : public SV {
private:
	string tenLuanVan;
	float diemLuanVan;
public:
	void Nhap() override {
		cout << "Nhap thong tin sinh vien dai hoc: " << endl;
		SV::Nhap();
		cout << "Nhap ten luan van: ";
		cin.ignore();
		getline(cin, tenLuanVan);
		cout << "Nhap diem luan van: ";
		cin >> diemLuanVan;
	}

	void Xuat() const override {
		cout << "Sinh vien dai hoc: " << endl;
		SV::Xuat();
		cout << " | Ten luan van: " << tenLuanVan
			<< " | Diem luan van: " << diemLuanVan << endl;
	}

	bool KiemTraTotNghiep() const override {
		return (SoTinChi >= 170 && diemTB >= 5.0 && diemLuanVan >= 5.0);
	}
};

int main() {
	SV* sv1 = new SVCaoDang();
	SV* sv2 = new SVDaiHoc();

	sv1->Nhap();
	sv2->Nhap();

	cout << "Danh sach sinh vien:\n";
	sv1->Xuat();
	sv2->Xuat();

	cout << "Ket qua tot nghiep:\n";
	cout << "Sinh vien cao dang: " << (sv1->KiemTraTotNghiep() ? "Du dieu kien tot nghiep" : "Khong du dieu kien tot nghiep") << endl;
	cout << "Sinh vien dai hoc: " << (sv2->KiemTraTotNghiep() ? "Du dieu kien tot nghiep" : "Khong du dieu kien tot nghiep") << endl;

	delete sv1;
	delete sv2;
	return 0;
}