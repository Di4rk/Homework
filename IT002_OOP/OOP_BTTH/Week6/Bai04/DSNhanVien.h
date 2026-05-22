#pragma once
#include "KiemChung.h"
#include "LapTrinh.h"
#include <vector>
class DSNhanVien
{
private:
	std::vector<NhanVien*> ds;
public:
	void Nhap();
	void Xuat();

	void NVDuoiTB();
	void NVLuongCaoNhat();
	void NVLuongThapNhat();

	void LapTrinhLuongCaoNhat();
	void KiemChungLuongThapNhat();

	~DSNhanVien();
};

