#pragma once
#include "ChuyenXe.h"

class NgoaiThanh : public ChuyenXe {
private:
    string noiDen;
    int soNgay;
public:
    void Nhap() override;
    void Xuat() override;
};