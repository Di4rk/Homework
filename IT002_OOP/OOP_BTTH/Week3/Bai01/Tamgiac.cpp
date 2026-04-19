	#include "Tamgiac.h"
	#include <iostream>
	#include <cmath>
	using namespace std;

	const double PI = 3.14159265359;

	cTamGiac::cTamGiac() {
		a.x = a.y = 0;
		b.x = b.y = 0;
		c.x = c.y = 0;
	}

	istream& operator>>(istream& is, cTamGiac& tg) {
		cout << "Nhap diem A: ";
		is >> tg.a.x >> tg.a.y;
		cout << "Nhap diem B: ";
		is >> tg.b.x >> tg.b.y;
		cout << "Nhap diem C: ";
		is >> tg.c.x >> tg.c.y;
		return is;
	}

	ostream& operator<<(ostream& os, cTamGiac tg) {
		os << "Diem A: (" << tg.a.x << ", " << tg.a.y << ")\n";
		os << "Diem B: (" << tg.b.x << ", " << tg.b.y << ")\n";
		os << "Diem C: (" << tg.c.x << ", " << tg.c.y << ")\n";
		return os;
	}

	float cTamGiac::KhoangCach(Diem p1, Diem p2) {
		return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
	}

	void cTamGiac::KiemTra() {
		float AB = KhoangCach(a, b);
		float BC = KhoangCach(b, c);
		float CA = KhoangCach(c, a);

		if (AB + BC < CA || AB + CA < BC || BC + CA < AB) {
			cout << "Tam giac khong hop le.\n";
		}
		else if (AB == BC && BC == CA) {
			cout << "Tam giac deu.\n";
		}
		else if (AB == BC || BC == CA || CA == AB) {
			cout << "Tam giac can.\n";
		}
		else if (pow(AB, 2) + pow(BC, 2) == pow(CA, 2) ||
			pow(BC, 2) + pow(CA, 2) == pow(AB, 2) ||
			pow(CA, 2) + pow(AB, 2) == pow(BC, 2)) {
			cout << "Tam giac vuong.\n";
		}
		else {
			cout << "Tam giac thuong.\n";
		}
	}

	float cTamGiac::ChuVi() {
		return KhoangCach(a, b) + KhoangCach(b, c) + KhoangCach(c, a);
	}

	float cTamGiac::DienTich() {
		float p = ChuVi() / 2;
		return sqrt(p * (p - KhoangCach(a, b)) * (p - KhoangCach(b, c)) * (p - KhoangCach(c, a)));
	}

	void cTamGiac::Quay(float goc) {
		float rad = goc * PI / 180;
		float cosGoc = cos(rad);
		float sinGoc = sin(rad);
		Diem tempA = a;
		a.x = tempA.x * cosGoc - tempA.y * sinGoc;
		a.y = tempA.x * sinGoc + tempA.y * cosGoc;
		Diem tempB = b;
		b.x = tempB.x * cosGoc - tempB.y * sinGoc;
		b.y = tempB.x * sinGoc + tempB.y * cosGoc;
		Diem tempC = c;
		c.x = tempC.x * cosGoc - tempC.y * sinGoc;
		c.y = tempC.x * sinGoc + tempC.y * cosGoc;
	}

	void cTamGiac::TinhTien(float dx, float dy) {
		a.x += dx;
		a.y += dy;
		b.x += dx;
		b.y += dy;
		c.x += dx;
		c.y += dy;
	}

	void cTamGiac::PhongTo(float heso) {
		a.x *= heso;
		a.y *= heso;
		b.x *= heso;
		b.y *= heso;
		c.x *= heso;
		c.y *= heso;
	}

	void cTamGiac::ThuNho(float heso) {
		a.x /= heso;
		a.y /= heso;
		b.x /= heso;
		b.y /= heso;
		c.x /= heso;
		c.y /= heso;
	}