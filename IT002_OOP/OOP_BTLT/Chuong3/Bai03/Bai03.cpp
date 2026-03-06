#include <iostream>
using namespace std;

class Diem {
private:
	float x, y;
public:
	void Nhap();
	void Xuat();
	float KhoangCach(Diem other);
};

void Diem::Nhap() {
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
}

float Diem::KhoangCach(Diem other) {
	return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

void Diem::Xuat() {
	cout << "Diem: (" << x << ", " << y << ")" << endl;
}

int main() {
	Diem p1, p2;
	cout << "Nhap diem thu nhat: " << endl;
	p1.Nhap();
	cout << "Nhap diem thu hai: " << endl;
	p2.Nhap();
	cout << "Khoang cach giua hai diem la: " << p1.KhoangCach(p2) << endl;
}