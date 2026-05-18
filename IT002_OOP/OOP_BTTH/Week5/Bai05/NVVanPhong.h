#pragma once
#include "NhanVien.h"

class NVVanPhong : public NhanVien {
private:
    int soNgayLamViec;
public:
    void Nhap() override;
    void Xuat() override;
    void TinhLuong() override;
};