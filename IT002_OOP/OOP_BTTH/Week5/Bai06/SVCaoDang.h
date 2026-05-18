#pragma once
#include "SinhVien.h"

class SVCaoDang : public SinhVien {
private:
    double diemThiTN;
public:
    void Nhap() override;
    void Xuat() override;
    bool XetTotNghiep() override;
};