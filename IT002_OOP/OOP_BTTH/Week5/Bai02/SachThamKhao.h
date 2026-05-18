#pragma once
#include "Sach.h"

class SachThamKhao : public Sach {
private:
    double thue;
public:
    void Nhap() override;
    void Xuat() override;
    double TinhThanhTien() override;
};