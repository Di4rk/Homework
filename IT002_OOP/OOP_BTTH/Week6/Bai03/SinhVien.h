#pragma once
#include <iostream>
#include <string>

class SinhVien{
protected:
	std::string maSV, hoTen;
	int tongSoTinChi;
	float diemTrungBinh;
public:
	virtual void Nhap();
	virtual void Xuat();

	virtual bool TotNghiep() = 0;
	float getDiemTrungBinh() const;

	virtual ~SinhVien();
};

