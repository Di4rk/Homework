#pragma once
#include "ChuyenXe.h"

class NoiThanh : public ChuyenXe {
private:
    int soTuyen;
    double soKm;
public:
    void Nhap() override;
    void Xuat() override;
};