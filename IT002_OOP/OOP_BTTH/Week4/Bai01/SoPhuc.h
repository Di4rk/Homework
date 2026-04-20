#pragma once
#include <iostream>
using namespace std;

class SoPhuc {
private:
	float thuc, ao;
public:
	SoPhuc();
	SoPhuc(float thuc, float ao);
	
	SoPhuc operator+(SoPhuc sp);
	SoPhuc operator-(SoPhuc sp);
	SoPhuc operator*(SoPhuc sp);
	SoPhuc operator/(SoPhuc sp);

	bool operator==(SoPhuc sp);
	bool operator!=(SoPhuc sp);

	SoPhuc operator=(SoPhuc sp);

	SoPhuc operator+=(SoPhuc sp);
	SoPhuc operator-=(SoPhuc sp);
	SoPhuc operator*=(SoPhuc sp);
	SoPhuc operator/=(SoPhuc sp);

	friend istream& operator>>(istream& in, SoPhuc &sp);
	friend ostream& operator<<(ostream& out, const SoPhuc &sp);
};