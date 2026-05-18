#pragma once
#include <iostream>
#include <string>
using namespace std;

class GiaoDichBDS {
protected:
    string maGD;
    string ngayGD;
    double donGia;
    double dienTich;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhThanhTien() = 0;
    string getNgayGD();
};