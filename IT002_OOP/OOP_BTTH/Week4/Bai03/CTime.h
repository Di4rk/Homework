#pragma once
#include <iostream>
using namespace std;

class CTime {
private:
	int h, m, s;
	void ChuanHoa();
public:
	CTime(int h = 0, int m = 0, int s = 0);

	CTime operator+(int giay) const;
	CTime operator-(int giay) const;

	CTime& operator++();
	CTime operator++(int);
	CTime& operator--();
	CTime operator--(int);

	friend istream& operator>>(istream& in, CTime& t);
	friend ostream& operator<<(ostream& out, const CTime& t);
};