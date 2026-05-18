#pragma once
#include <iostream>
#include <string>
using namespace std;

class ChuyenXe {
protected:
    string maSo;
    string hoTenTaiXe;
    string soXe;
    double doanhThu;
public:
    virtual void Nhap();
    virtual void Xuat();
    double getDoanhThu();
};