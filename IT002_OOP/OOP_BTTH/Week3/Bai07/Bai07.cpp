#include "cNhanVienVP.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "=== HE THONG QUAN LY NHAN VIEN VAN PHONG ===\n";

    cDSNhanVienVP congTy;
    congTy.nhap();

    cout << "\n[>] Danh sach nhan vien:\n";
    congTy.xuatDanhSach();

    cout << "\n[>] Nhan vien co luong cao nhat:\n";
    cNhanVienVP nvMax = congTy.timNhanVienLuongCaoNhat();
    nvMax.xuat();

    cout << "\n[+] Tong luong cong ty phai tra: "
        << fixed << setprecision(0) << congTy.tinhTongLuong() << "\n";

    cout << "\n[>] Nhan vien co tuoi cao nhat (Lao lang nhat):\n";
    cNhanVienVP nvOldest = congTy.timNhanVienTuoiCaoNhat();
    nvOldest.xuat();

    cout << "\n[>] Danh sach nhan vien sap xep luong tang dan:\n";
    congTy.sapXepLuongTangDan();
    congTy.xuatDanhSach();

    cout << "\n=== FINISH ===\n";
    return 0;
}