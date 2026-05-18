#pragma once
#include "GiaoDich.h"

class GiaoDichTienTe : public GiaoDich {
private:
    double tiGia;
    int loaiTien;
public:
    void Nhap() override;
    void Xuat() override;
    double TinhThanhTien() override;
    int getLoaiTien();
};