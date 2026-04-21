#pragma once
#include <iostream>
using namespace std;

class DaThuc {
private:
	int bac;
	double* heso;

	void ChuanHoa();
public:
	DaThuc(int b = 0);
	~DaThuc();
	DaThuc(const DaThuc& dt);
	DaThuc& operator=(const DaThuc& dt);

	DaThuc operator+(const DaThuc& dt) const;
	DaThuc operator-(const DaThuc& dt) const;

	friend istream& operator>>(istream& is, DaThuc& dt);
	friend ostream& operator<<(ostream& os, const DaThuc& dt);
};