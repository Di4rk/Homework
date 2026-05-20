#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Date {
	int day, month, year;
};

class NhanVien {
protected:
	string HoTen;
	Date NgaySinh;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual long long TinhLuong() = 0;
	virtual ~NhanVien();
};