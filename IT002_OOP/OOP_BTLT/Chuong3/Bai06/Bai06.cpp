#include <iostream>
using namespace std;

class cSoPhuc {
private:
	double douAo;
	double douThuc;
public:
	cSoPhuc(double thuc = 0, double ao = 0) {
		douThuc = thuc;
		douAo = ao;
	}
	void Nhap();
	void Xuat();
	void ThayDoi(double thuc, double ao);
	double LayPhanAo();
	double LayPhanThuc();
	cSoPhuc Cong(cSoPhuc other);
	cSoPhuc Tru(cSoPhuc other);
	cSoPhuc Nhan(cSoPhuc other);
	cSoPhuc Chia(cSoPhuc other);
};

void cSoPhuc::Nhap() {
	cout << "Nhap phan thuc: ";
	cin >> douThuc;
	cout << "Nhap phan ao: ";
	cin >> douAo;
}

void cSoPhuc::Xuat() {
	cout << "\n(" << douThuc << "," << douAo << ")" << endl;
}

void cSoPhuc::ThayDoi(double thuc, double ao) {
	douThuc = thuc;
	douAo = ao;
}

double cSoPhuc::LayPhanAo() {
	return douAo;
}

double cSoPhuc::LayPhanThuc() {
	return douThuc;
}

cSoPhuc cSoPhuc::Cong(cSoPhuc other) {
	cSoPhuc ans;
	ans.douThuc = douThuc + other.douThuc;
	ans.douAo = douAo + other.douAo;
	return ans;
}

cSoPhuc cSoPhuc::Tru(cSoPhuc other) {
	cSoPhuc ans;
	ans.douThuc = douThuc - other.douThuc;
	ans.douAo = douAo - other.douAo;
	return ans;
}

cSoPhuc cSoPhuc::Nhan(cSoPhuc other) {
	cSoPhuc ans;
	ans.douThuc = douThuc * other.douThuc - douAo * other.douAo;
	ans.douAo = douThuc * other.douAo + douAo * other.douThuc;
	return ans;
}

cSoPhuc cSoPhuc::Chia(cSoPhuc other) {
	cSoPhuc ans;
	double mau = other.douThuc * other.douThuc + other.douAo * other.douAo;
	if (mau == 0) {
		cout << "Chia 0?" << endl;
		return ans;
	}
	ans.douThuc = (douThuc * other.douThuc + douAo * other.douAo) / mau;
	ans.douAo = (douAo * other.douThuc - douThuc * other.douAo) / mau;
	return ans;
}

int main() {
		cSoPhuc sp1, sp2, test;
	cout << "So phuc khoi tao bang ham tao mac dinh: ";
	test.Xuat();
	cout << "Gia tri phan thuc: " << test.LayPhanThuc() << ", gia tri phan ao: " << test.LayPhanAo() << endl;

	cout << "Nhap so phuc thu nhat" << endl;
	sp1.Nhap();

	cout << "Nhap so phuc thu hai" << endl;
	sp2.Nhap();

	cout << "Tong: ";
	cSoPhuc tong = sp1.Cong(sp2);
	tong.Xuat();

	cout << "Hieu: ";
	cSoPhuc hieu = sp1.Tru(sp2);
	hieu.Xuat();

	cout << "Tich: ";
	cSoPhuc tich = sp1.Nhan(sp2);
	tich.Xuat();

	cout << "Thuong: ";
	cSoPhuc thuong = sp1.Chia(sp2);
	thuong.Xuat();
	return 0;

}