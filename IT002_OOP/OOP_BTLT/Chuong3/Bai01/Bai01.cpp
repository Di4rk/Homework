#include <iostream>
#include <string>
using namespace std;

class HocSinh {
private:
	string HoTen;
	float DiemToan, DiemVan;
public:
	void Nhap();
	void Xuat();
	float DiemTrungBinh();
	void XepLoai();
};

void HocSinh::Nhap() {
	cout << "Nhap ho ten: ";
	getline(cin, HoTen);
	cout << "Nhap diem toan: ";
	cin >> DiemToan;
	cout << "Nhap diem van: ";
	cin >> DiemVan;
}

float HocSinh::DiemTrungBinh() {
	return (DiemToan + DiemVan) / 2;
}

void HocSinh::XepLoai() {
	float avg = DiemTrungBinh();
	if (avg >= 9)
		cout << "Xep loai: Xuat sac" << endl;
	else if (avg >= 8)
		cout << "Xep loai: Gioi" << endl;
	else if (avg >= 5)
		cout << "Xep loai: Trung binh" << endl;
	else
		cout << "Xep loai: Yeu" << endl;
}

void HocSinh::Xuat() {
	cout << "Ho ten: " << HoTen << endl;
	cout << "Diem toan: " << DiemToan << endl;
	cout << "Diem van: " << DiemVan << endl;
	cout << "Diem trung binh: " << DiemTrungBinh() << endl;
	XepLoai();
}

int main() {
	HocSinh hs;
	hs.Nhap();
	hs.Xuat();
	return 0;
}
