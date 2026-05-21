#pragma once
#include "GiaoDich.h"
class GiaoDichNhaPho : public GiaoDich {
private:
	int loaiNha;
	std::string diaChi;
public:
	void Nhap() override;
	void Xuat() override;

	double ThanhTien() override;

};

