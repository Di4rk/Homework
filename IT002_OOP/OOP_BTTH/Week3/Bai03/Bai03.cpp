#include "cDSPhanSo.h"
#include <iostream>

using namespace std;

int main() {
    cout << "--- HE THONG QUAN LY DANH SACH PHAN SO (UIT) ---\n";
    cDSPhanSo list;
    list.nhap();

    cout << "\n[>] Danh sach vua nhap: ";
    list.xuat();

    PhanSo tong = list.tinhTong();
    cout << "\n[+] Tong cac phan so: " << tong.tu << "/" << tong.mau << endl;

    PhanSo max = list.timMax();
    cout << "[+] Phan so lon nhat: " << max.tu << "/" << max.mau << endl;

    PhanSo min = list.timMin();
    cout << "[+] Phan so nho nhat: " << min.tu << "/" << min.mau << endl;

    PhanSo sntMax = list.timPhanSoCoTuLaSNTMax();
    if (sntMax.mau != 0) {
        cout << "[+] Phan so co tu la SNT lon nhat: " << sntMax.tu << "/" << sntMax.mau << endl;
    }
    else {
        cout << "[!] Khong co phan so nao co tu la so nguyen to." << endl;
    }

    cout << "\n[>] Sap xep tang dan: ";
    list.sapXepTang();
    list.xuat();

    cout << "[>] Sap xep giam dan: ";
    list.sapXepGiam();
    list.xuat();

    cout << "\n--- FINISH DEADLINE ---" << endl;
    return 0;
}