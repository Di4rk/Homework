#pragma once
#include "GiaoDich.h"
#include <vector>
class DanhSachGiaoDich{
private: 
	std::vector<GiaoDich*> ds;
public:
	void Nhap();
	void Xuat();

	int TongSoLuongTungLoai();
	double averageThanhTienChungCu();
	double maxValueGDNhaPho();

	void XuatGiaoDichThang12Nam2024();
	~DanhSachGiaoDich();
};

