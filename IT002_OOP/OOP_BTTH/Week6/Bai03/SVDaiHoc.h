#pragma once
#include "SinhVien.h"
class SVDaiHoc :
    public SinhVien
{
private: 
    std::string tenLuanVan;
    float diemLuanVan;
public:
    void Nhap() override;
    void Xuat() override;

    bool TotNghiep() override;
};

