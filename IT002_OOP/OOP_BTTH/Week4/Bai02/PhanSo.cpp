#include "PhanSo.h"

PhanSo::PhanSo(int tu, int mau) {
	if (mau == 0) {
		cout << "Canh bao: Mau so = 0! Tu dong set mau = 1.\n";
		mau = 1;
	}
	if (mau < 0) {
		this->tu = -tu;
		this->mau = -mau;
	}
	else {
		this->tu = tu;
		this->mau = mau;
	}
}

PhanSo PhanSo::operator+(const PhanSo& ps) const {
	int tuMoi = this->tu * ps.mau + ps.tu * this->mau;
	int mauMoi = this->mau * ps.mau;
	return PhanSo(tuMoi, mauMoi);
}

PhanSo PhanSo::operator-(const PhanSo& ps) const {
	int tuMoi = this->tu * ps.mau - ps.tu * this->mau;
	int mauMoi = this->mau * ps.mau;
	return PhanSo(tuMoi, mauMoi);
}

PhanSo PhanSo::operator*(const PhanSo& ps) const {
	return PhanSo(this->tu * ps.tu, this->mau * ps.mau);
}

PhanSo PhanSo::operator/(const PhanSo& ps) const {
	return PhanSo(this->tu * ps.mau, this->mau * ps.tu);
}

bool PhanSo::operator==(const PhanSo& ps) const {
	return this->tu * ps.mau == ps.tu * this->mau;
}

bool PhanSo::operator>(const PhanSo& ps) const {
	return this->tu * ps.mau > ps.tu * this->mau;
}

bool PhanSo::operator<(const PhanSo& ps) const {
	return this->tu * ps.mau < ps.tu * this->mau;
}

bool PhanSo::operator>=(const PhanSo& ps) const {
	return this->tu * ps.mau >= ps.tu * this->mau;
}

bool PhanSo::operator<=(const PhanSo& ps) const {
	return this->tu * ps.mau <= ps.tu * this->mau;
}

bool PhanSo::operator!=(const PhanSo& ps) const {
	return !(*this == ps);
}

PhanSo& PhanSo::operator=(const PhanSo& ps) {
	this->tu = ps.tu;
	this->mau = ps.mau;
	return *this;
}

PhanSo& PhanSo::operator+=(const PhanSo& ps) {
	*this = *this + ps;
	return *this;
}

PhanSo& PhanSo::operator-=(const PhanSo& ps) {
	*this = *this - ps;
	return *this;
}

PhanSo& PhanSo::operator*=(const PhanSo& ps) {
	*this = *this * ps;
	return *this;
}

PhanSo& PhanSo::operator/=(const PhanSo& ps) {
	*this = *this / ps;
	return *this;
}

PhanSo& PhanSo::operator++() {
	*this += PhanSo(1, 1);
	return *this;
}

PhanSo PhanSo::operator++(int) { 
	PhanSo temp = *this;
	*this += PhanSo(1, 1);
	return temp; 
}

PhanSo& PhanSo::operator--() {
	*this -= PhanSo(1, 1);
	return *this;
}

PhanSo PhanSo::operator--(int) {
	PhanSo temp = *this;
	*this -= PhanSo(1, 1);
	return temp;
}

istream& operator>>(istream& in, PhanSo& ps) {
	in >> ps.tu >> ps.mau;
	ps = PhanSo(ps.tu, ps.mau);
	return in;
}

ostream& operator<<(ostream& out, const PhanSo& ps) {
	if (ps.mau == 1) out << ps.tu; 
	else out << ps.tu << "/" << ps.mau;
	return out;
}