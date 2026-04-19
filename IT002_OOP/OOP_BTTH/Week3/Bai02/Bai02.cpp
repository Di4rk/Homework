#include "cDaGiac.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    cout << "========== CHUONG TRINH XU LY DA GIAC ==========\n" << endl;

    cDaGiac dg;

    dg.nhap();
    cout << "\n[+] Da giac ban dau: \n";
    dg.xuat();

    cout << "\n[+] Thong so: \n";
    cout << "- Chu vi: " << dg.tinhChuVi() << endl;
    cout << "- Dien tich: " << dg.tinhDienTich() << endl;

    float dx = 2.0, dy = -1.5;
    cout << "\n[+] Tinh tien voi vector v(" << dx << ", " << dy << "):\n";
    dg.tinhTien(dx, dy);
    dg.xuat();

    float heSoPhong = 2.0;
    cout << "\n[+] Phong to " << heSoPhong << " lan (so voi goc toa do):\n";
    dg.phongTo(heSoPhong);
    dg.xuat();

    float gocQuay = 90.0;
    cout << "\n[+] Quay " << gocQuay << " do (nguoc chieu kim dong ho):\n";
    dg.quay(gocQuay);
    dg.xuat();

    cout << "\n========== KET THUC ==========\n";
    return 0;
}