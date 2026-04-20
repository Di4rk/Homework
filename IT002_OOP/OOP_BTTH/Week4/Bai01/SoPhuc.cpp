#include "SoPhuc.h"
#include <cmath>

SoPhuc::SoPhuc() {
	this->thuc = 0;
	this->ao = 0;
}

SoPhuc::SoPhuc(float thuc, float ao) : thuc(thuc), ao(ao) {}

SoPhuc SoPhuc::operator+(SoPhuc sp) {
	return SoPhuc(this->thuc + sp.thuc, this->ao + sp.ao);
}

SoPhuc SoPhuc::operator-(SoPhuc sp) {
	return SoPhuc(this->thuc - sp.thuc, this->ao - sp.ao);
}

SoPhuc SoPhuc::operator*(SoPhuc sp) {
	return SoPhuc(this->thuc * sp.thuc - this->ao * sp.ao, this->thuc * sp.ao + this->ao * sp.thuc);
}

SoPhuc SoPhuc::operator/(SoPhuc sp) {
	float denominator = sp.thuc * sp.thuc + sp.ao * sp.ao;
	return SoPhuc((this->thuc * sp.thuc + this->ao * sp.ao) / denominator, (this->ao * sp.thuc - this->thuc * sp.ao) / denominator);
}

bool SoPhuc::operator==(SoPhuc sp) {
	return this->thuc == sp.thuc && this->ao == sp.ao;
}

bool SoPhuc::operator!=(SoPhuc sp) {
	return !(*this == sp);
}

SoPhuc SoPhuc::operator=(SoPhuc sp) {
	return SoPhuc(this->thuc = sp.thuc, this->ao = sp.ao);
}

SoPhuc SoPhuc::operator+=(SoPhuc sp) {
	this->thuc += sp.thuc;
	this->ao += sp.ao;
	return *this;
}

SoPhuc SoPhuc::operator-=(SoPhuc sp) {
	this->thuc -= sp.thuc;
	this->ao -= sp.ao;
	return *this;
}

SoPhuc SoPhuc::operator*=(SoPhuc sp) {
	float tempThuc = this->thuc * sp.thuc - this->ao * sp.ao;
	this->ao = this->thuc * sp.ao + this->ao * sp.thuc;
	this->thuc = tempThuc;
	return *this;
}

SoPhuc SoPhuc::operator/=(SoPhuc sp) {
	float denominator = sp.thuc * sp.thuc + sp.ao * sp.ao;
	float tempThuc = (this->thuc * sp.thuc + this->ao * sp.ao) / denominator;
	this->ao = (this->ao * sp.thuc - this->thuc * sp.ao) / denominator;
	this->thuc = tempThuc;
	return *this;
}

istream& operator>>(istream& in, SoPhuc& sp) {
	cout << "Nhap phan thuc: ";
	in >> sp.thuc;
	cout << "Nhap phan ao: ";
	in >> sp.ao;
	return in;
}

ostream& operator<<(ostream& out, const SoPhuc &sp) {
	out << sp.thuc << " + " << sp.ao << "i";
	return out;
}