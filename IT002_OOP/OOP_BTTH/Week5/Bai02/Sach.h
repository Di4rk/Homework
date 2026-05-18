#pragma once
#include <iostream>
#include <string>
using namespace std;

class Sach {
protected:
    string maSach;
    string ngayNhap;
    double donGia;
    int soLuong;
    string nxb;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhThanhTien() = 0;
    string getNxb();
    double getDonGia();
};