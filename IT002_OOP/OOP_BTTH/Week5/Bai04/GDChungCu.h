#pragma once
#include "GiaoDichBDS.h"

class GDChungCu : public GiaoDichBDS {
private:
    string maCan;
    int viTriTang;
public:
    void Nhap() override;
    void Xuat() override;
    double TinhThanhTien() override;
};