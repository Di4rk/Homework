#pragma once
#include <iostream>
#include <string>
using namespace std;

class SinhVien {
protected:
    string maSSV;
    string hoTen;
    string diaChi;
    int tongTinChi;
    double diemTB;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual bool XetTotNghiep() = 0;
    double getDiemTB();
};