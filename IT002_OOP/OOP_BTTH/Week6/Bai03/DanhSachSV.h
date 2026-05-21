#pragma once
#include "SVDaiHoc.h"
#include "SVCaoDang.h"
#include <vector>
class DanhSachSV
{
private:
	std::vector<SinhVien*> ds;
public:
	void Nhap();
	void Xuat();

	void XuatSVTotNghiep();
	void XuatSVKoTotNghiep();

	SinhVien* SVDaiHocCoDiemTrungBinhCaoNhat();
	SinhVien* SVCaoDangCoDiemTrungBinhCaoNhat();

	void SoLuongSVKoTotNghiepTheoLoai();

	~DanhSachSV();
};

