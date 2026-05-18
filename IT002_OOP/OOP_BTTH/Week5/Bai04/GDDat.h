#pragma once
#include "GiaoDichBDS.h"

class GDDat : public GiaoDichBDS {
private:
    string loaiDat;
public:
    void Nhap() override;
    void Xuat() override;
    double TinhThanhTien() override;
};