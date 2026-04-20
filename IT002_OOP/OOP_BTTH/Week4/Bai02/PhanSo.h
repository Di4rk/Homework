#pragma once
#include <iostream>
using namespace std;

class PhanSo {
private:
	int tu, mau;
public:
	PhanSo(int tu = 0, int mau = 1);

	PhanSo operator+(const PhanSo& ps) const;
	PhanSo operator-(const PhanSo& ps) const;
	PhanSo operator*(const PhanSo& ps) const;
	PhanSo operator/(const PhanSo& ps) const;

	bool operator==(const PhanSo& ps) const;
	bool operator>(const PhanSo& ps) const;
	bool operator<(const PhanSo& ps) const;
	bool operator>=(const PhanSo& ps) const;
	bool operator<=(const PhanSo& ps) const;
	bool operator!=(const PhanSo& ps) const;

	PhanSo& operator=(const PhanSo& ps);

	PhanSo& operator+=(const PhanSo& ps);
	PhanSo& operator-=(const PhanSo& ps);
	PhanSo& operator*=(const PhanSo& ps);
	PhanSo& operator/=(const PhanSo& ps);

	PhanSo& operator++();    
	PhanSo operator++(int);  
	PhanSo& operator--();
	PhanSo operator--(int);

	friend istream& operator>>(istream& in, PhanSo& ps);
	friend ostream& operator<<(ostream& out, const PhanSo& ps); 
};