#pragma once
#include <iostream>
#include <string>

class KhachHang
{
protected:
	std::string TenKH;
	int soLuong;
	double donGia;
public:
	virtual void Nhap(std::istream &in);
	virtual void Xuat(std::ostream &out);

	virtual double ThanhTien() = 0;

	virtual ~KhachHang();
};

