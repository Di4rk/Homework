#pragma once
#include "NhanVien.h"
#include <vector>

class DanhSachNhacVien {
private:
	vector<NhacVien*> ds;
public:
	void Nhap();
	void Xuat();
	long long TongLuong();
	void LuongThapNhat();
	void TuoiCaoNhat();
	~DanhSachNhacVien();
};