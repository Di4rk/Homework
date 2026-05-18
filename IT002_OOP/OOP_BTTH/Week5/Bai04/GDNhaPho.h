#pragma once
#include "GiaoDichBDS.h"

class GDNhaPho : public GiaoDichBDS {
private:
    int loaiNha;
    string diaChi;
public:
    void Nhap() override;
    void Xuat() override;
    double TinhThanhTien() override;
};