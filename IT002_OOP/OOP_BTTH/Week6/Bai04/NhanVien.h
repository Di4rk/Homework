#pragma once
#include <iostream>
#include <string>

class NhanVien
{
protected:
	std::string maNV, hoTen, soDT, email;
	int tuoi;
	double luongCoBan;
public:
	virtual void Nhap();
	virtual void Xuat();

	virtual double Luong() = 0;

	virtual ~NhanVien();
};

