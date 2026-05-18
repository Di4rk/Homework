#pragma once
#include "Sach.h"

class SachGiaoKhoa : public Sach {
private:
    int tinhTrang;
public:
    void Nhap() override;
    void Xuat() override;
    double TinhThanhTien() override;
};