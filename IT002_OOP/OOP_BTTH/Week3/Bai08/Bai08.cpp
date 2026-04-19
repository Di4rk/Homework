#include "cNhanVienSX.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "=== HE THONG QUAN LY NHAN VIEN SAN XUAT ===\n";

    cDSNhanVienSX nhaMay;
    nhaMay.nhap();

    cout << "\n[>] Danh sach nhan vien san xuat:\n";
    nhaMay.xuatDanhSach();

    cout << "\n[>] Nhan vien co luong thap nhat:\n";
    cNhanVienSX nvMin = nhaMay.timNhanVienLuongThapNhat();
    nvMin.xuat();

    cout << "\n[+] Tong luong nha may phai tra: "
        << fixed << setprecision(0) << nhaMay.tinhTongLuong() << "\n";

    cout << "\n[>] Nhan vien co tuoi cao nhat (Lao lang nhat):\n";
    cNhanVienSX nvOldest = nhaMay.timNhanVienTuoiCaoNhat();
    nvOldest.xuat();

    cout << "\n[>] Danh sach nhan vien sap xep luong tang dan:\n";
    nhaMay.sapXepLuongTangDan();
    nhaMay.xuatDanhSach();

    cout << "\n=== CHUC MUNG CLEAR DEADLINE THANH CONG ===\n";
    return 0;
}