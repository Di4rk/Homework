#pragma once
#include <iostream>
#include <string>

struct Date {
	int day, month, year;
};

class GiaoDich {
protected:
	std::string maGiaoDich;
	Date ngayGiaoDich;
	double DonGia;
	double DienTich;
public:
	virtual void Nhap();
	virtual void Xuat();
	
	virtual bool getDate();
	virtual double ThanhTien() = 0;

	~GiaoDich();
};

