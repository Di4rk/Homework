#pragma once
#include "KhachHang.h"
class KhachThan: public KhachHang
{
private:
	int soNamThanThiet;
public:
	void Nhap(std::istream& in) override;
	double ThanhTien() override;
};

