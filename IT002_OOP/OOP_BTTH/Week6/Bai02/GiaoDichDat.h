#pragma once
#include "GiaoDich.h"
class GiaoDichDat : public GiaoDich {
private:
	char loaiDat;
public:
	void Nhap() override;
	void Xuat() override;
	
	double ThanhTien() override;

};

