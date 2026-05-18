#pragma once
#include <iostream>
#include <string>
using namespace std;

class NhanVien {
protected:
    string hoTen;
    string ngaySinh;
    double luong;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhLuong() = 0;
    double getLuong();
};