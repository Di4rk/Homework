#pragma once
#include "NhanVien.h"

class NVVanPhong : public NhanVien {
private:
	int SoNgayLamViec;
public:
	void Nhap() override;
	void Xuat() override;
	long long TinhLuong() override;
	~NVVanPhong() override;
};