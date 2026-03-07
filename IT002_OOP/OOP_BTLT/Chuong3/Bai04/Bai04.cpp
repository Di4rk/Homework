#include <iostream>
#include <string>
using namespace std;

class cHocSinh {
private:
	int imaHS;
	string stenHS;
	int iNamSinh;
	float fdiemTrungBinh;
public:
	void Nhap();
	void Xuat();
	bool SoSanhDTB(cHocSinh other);
	bool SoSanhNamSinh(cHocSinh other);
};

void cHocSinh::Nhap() {
	cout << "Nhap ma hoc sinh: ";
	cin >> imaHS;
	cin.ignore();
	cout << "Nhap ten hos sinh: ";
	getline(cin, stenHS);
	cout << "Nhap nam sinh: ";
	cin >> iNamSinh;
	cout << "Nhap diem trung binh: ";
	cin >> fdiemTrungBinh;
}

bool cHocSinh::SoSanhDTB(cHocSinh other) {
	return fdiemTrungBinh > other.fdiemTrungBinh;
}

bool cHocSinh::SoSanhNamSinh(cHocSinh other) {
	return iNamSinh < other.iNamSinh;
}

void cHocSinh::Xuat() {
	cout << "Ma hoc sinh: " << imaHS << endl;
	cout << "Ten hoc sinh: " << stenHS << endl;
	cout << "Nam sinh: " << iNamSinh << endl;
	cout << "Diem trung binh: " << fdiemTrungBinh << endl;
}

int main() {
	cHocSinh hs1, hs2;
	cout << "Nhap thong tin hoc sinh thu nhat" << endl;
	hs1.Nhap();
	cout << "\nNhap thong tin hoc sinh thu hai" << endl;
	hs2.Nhap();

	cout << "\nHoc sinh co diem trung binh cao hon:\n";
	if (hs1.SoSanhDTB(hs2)) {
		hs1.Xuat();
	} else {
		hs2.Xuat();
	}

	cout << "\nHoc sinh co nam sinh nho hon:\n";
	if (hs1.SoSanhNamSinh(hs2)) {
		hs1.Xuat();
	} else {
		hs2.Xuat();
	}	

	return 0;
}