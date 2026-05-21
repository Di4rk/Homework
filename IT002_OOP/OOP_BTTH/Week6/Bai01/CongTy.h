#pragma once
#include "NhanVien.h"
#include <vector>

class DanhSachNhanVien {
private:
	std::vector<NhanVien*> ds;
public:
	void Nhap();
	void Xuat();
	long long TongLuong();
	void LuongThapNhat(); 
	void TuoiCaoNhat();

	~DanhSachNhanVien();
};