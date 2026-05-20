#pragma once
#include "NhanVien.h"

class NVSanXuat : public NhanVien {
private:
	long LuongCanBan;
	int SoSanPham;
public:
	void Nhap() override;
	void Xuat() override;
	long long TinhLuong() override;
	~NVSanXuat() override;
};