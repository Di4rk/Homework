#pragma once
#include <iostream>
#include <string>
using namespace std;

class GiaoDich {
protected:
    string maGD;
    string ngayGD;
    double donGia;
    int soLuong;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhThanhTien() = 0;
};