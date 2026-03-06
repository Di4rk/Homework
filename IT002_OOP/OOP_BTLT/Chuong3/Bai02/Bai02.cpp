#include <iostream>;
using namespace std;

class DuongTron {
private:
	pair <float, float> Tam;
	float BanKinh;
public:
	void Nhap();
	void Xuat();
	float ChuVi();
	float DienTich();
};
void DuongTron::Nhap() {
	cout << "Nhap tam  (x, y): " << endl;
	cout << "x = ";
	cin >> Tam.first;
	cout << "y = ";
	cin >> Tam.second;
	cout << "Nhap ban kinh: ";
	cin >> BanKinh;
}
float DuongTron::ChuVi() {
	return 2 * 3.14 * BanKinh;
}
float DuongTron::DienTich() {
	return 3.14 * BanKinh * BanKinh;
}
void DuongTron::Xuat() {
	cout << "Tam: (" << Tam.first << ", " << Tam.second << ")" << endl;
	cout << "Ban kinh: " << BanKinh << endl;
	cout << "Chu vi: " << ChuVi() << endl;
	cout << "Dien tich: " << DienTich() << endl;
}

int main() {
	DuongTron dt;
	dt.Nhap();
	dt.Xuat();
	return 0;
}