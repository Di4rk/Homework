#pragma once
#include "NhanVien.h"

class NVSanXuat : public NhanVien {
private:
    double luongCanBan;
    int soSanPham;
public:
    void Nhap() override;
    void Xuat() override;
    void TinhLuong() override;
};