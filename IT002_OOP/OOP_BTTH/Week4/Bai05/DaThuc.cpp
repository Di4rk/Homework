#include "DaThuc.h"

void DaThuc::ChuanHoa() {
	while (bac > 0 && heso == 0) {
		bac--;
	}
}

DaThuc::DaThuc(int b) {
	bac = b;
	heso = new double[bac + 1];
	for (int i = 0; i <= bac; i++) {
		heso[i] = 0;
	}
}

DaThuc::~DaThuc() {
	delete[] heso;
}

DaThuc::DaThuc(const DaThuc& dt) {
	bac = dt.bac;
	heso = new double[bac + 1];
	for (int i = 0; i <= bac; i++) {
		heso[i] = dt.heso[i];
	}
}

DaThuc& DaThuc::operator=(const DaThuc& dt) {
	if (this != &dt) {
		delete[] heso;
		bac = dt.bac;
		heso = new double[bac + 1];
		for (int i = 0; i <= bac; i++) {
			heso[i] = dt.heso[i];
		}
	}
	return *this;
}

DaThuc DaThuc::operator+(const DaThuc& dt) const {
	DaThuc result(max(bac, dt.bac));
	for (int i = 0; i <= result.bac; i++) {
		double h1 = (i <= bac) ? heso[i] : 0;
		double h2 = (i <= dt.bac) ? dt.heso[i] : 0;
		result.heso[i] = h1 + h2;
	}
	result.ChuanHoa();
	return result;
}

DaThuc DaThuc::operator-(const DaThuc& dt) const {
	DaThuc result(max(bac, dt.bac));
	for (int i = 0; i <= result.bac; i++) {
		double h1 = (i <= bac) ? heso[i] : 0;
		double h2 = (i <= dt.bac) ? dt.heso[i] : 0;
		result.heso[i] = h1 - h2;
	}
	result.ChuanHoa();
	return result;
}

istream& operator>>(istream& is, DaThuc& dt) {
	cout << "Nhap bac cua da thuc: ";
	is >> dt.bac;
	delete[] dt.heso;
	dt.heso = new double[dt.bac + 1];
	for (int i = 0; i <= dt.bac; i++) {
		cout << "Nhap he so x^" << i << ": ";
		is >> dt.heso[i];
	}
	dt.ChuanHoa();
	return is;
}

ostream& operator<<(ostream& os, const DaThuc& dt) {
	for (int i = dt.bac; i >= 0; i--) {
		if (dt.heso[i] != 0) {
			if (i < dt.bac && dt.heso[i] > 0) {
				os << " + ";
			} else if (dt.heso[i] < 0) {
				os << " - ";
			}
			os << abs(dt.heso[i]);
			if (i > 0) {
				os << "x";
				if (i > 1) {
					os << "^" << i;
				}
			}
		}
	}
	return os;
}


	