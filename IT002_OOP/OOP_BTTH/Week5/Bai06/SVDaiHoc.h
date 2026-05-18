#pragma once
#include "SinhVien.h"

class SVDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;
public:
    void Nhap() override;
    void Xuat() override;
    bool XetTotNghiep() override;
};