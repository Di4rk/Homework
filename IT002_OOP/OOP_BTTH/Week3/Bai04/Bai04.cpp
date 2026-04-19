#include "cArray.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== CHUONG TRINH XU LY MANG 1 CHIEU ===\n";

    cArray mang;
    int soLuong;

    cout << "Nhap so luong phan tu cho mang: ";
    cin >> soLuong;

    mang.taoMangNgauNhien(soLuong);

    cout << "\n[>] Mang ngau nhien vua tao:\n";
    mang.xuat();

    int x;
    cout << "\nNhap gia tri x can dem: ";
    cin >> x;
    cout << "[+] So lan xuat hien cua " << x << " la: " << mang.demSoLanXuatHien(x) << "\n";

    if (mang.kiemTraTangDan()) {
        cout << "[+] Mang dang duoc sap xep tang dan.\n";
    }
    else {
        cout << "[+] Mang KHONG tang dan.\n";
    }

    int leNhoNhat = mang.timLeNhoNhat();
    if (leNhoNhat != 1e9) {
        cout << "[+] Phan tu le nho nhat la: " << leNhoNhat << "\n";
    }
    else {
        cout << "[!] Khong co so le trong mang.\n";
    }

    int sntLonNhat = mang.timSNTLonNhat();
    if (sntLonNhat != -1e9) {
        cout << "[+] So nguyen to lon nhat la: " << sntLonNhat << "\n";
    }
    else {
        cout << "[!] Khong co so nguyen to trong mang.\n";
    }

    cout << "\n[>] Sap xep tang dan (dung Merge Sort):\n";
    mang.sapXepTang();
    mang.xuat();

    cout << "\n[>] Sap xep giam dan (dung Heap Sort):\n";
    mang.sapXepGiam();
    mang.xuat();

    cout << "\n=== HOAN THANH ===\n";
    return 0;
}