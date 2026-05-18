#include "ChuyenXe.h"

void ChuyenXe::Nhap() {
    cout << "Nhap ma so chuyen xe: ";
    cin.ignore();
    getline(cin, maSo);
    cout << "Nhap ho ten tai xe: ";
    getline(cin, hoTenTaiXe);
    cout << "Nhap so xe: ";
    getline(cin, soXe);
    cout << "Nhap doanh thu: ";
    cin >> doanhThu;
}

void ChuyenXe::Xuat() {
    cout << "Ma so: " << maSo << " | Tai xe: " << hoTenTaiXe
        << " | So xe: " << soXe << " | Doanh thu: " << doanhThu;
}

double ChuyenXe::getDoanhThu() {
    return doanhThu;
}