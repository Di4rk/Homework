#pragma once
#include "SinhVien.h"
class SVCaoDang :
    public SinhVien
{
private:
    float diemThiTotNghiep;
public:
    void Nhap() override;
    void Xuat() override;

    bool TotNghiep() override;
};

