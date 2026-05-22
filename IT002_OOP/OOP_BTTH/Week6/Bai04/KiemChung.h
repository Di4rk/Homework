#pragma once
#include "NhanVien.h"
class KiemChung :
    public NhanVien
{
private:
    int soLoiPhatHien;
public:
    void Nhap() override;
    void Xuat() override;

    double Luong() override;
};

