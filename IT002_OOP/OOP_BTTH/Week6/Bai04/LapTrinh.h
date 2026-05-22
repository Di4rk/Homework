#pragma once
#include "NhanVien.h"
class LapTrinh :
    public NhanVien
{
private:
    int soGioOvertime;
public:
    void Nhap() override;
    void Xuat() override;

    double Luong() override;
};

