#include "cDaThuc.h"
#include <iostream>

using namespace std;

int main() {
    cDaThuc dt1, dt2;

    cout << "--- NHAP DA THUC P(x) ---\n";
    dt1.nhap();

    cout << "\n--- NHAP DA THUC Q(x) ---\n";
    dt2.nhap();

    cout << "\n[>] P(x) = ";
    dt1.xuat();

    cout << "[>] Q(x) = ";
    dt2.xuat();

    float x;
    cout << "\nNhap gia tri x de tinh P(x) va Q(x): ";
    cin >> x;

    cout << "[+] P(" << x << ") = " << dt1.tinhGiaTri(x) << "\n";
    cout << "[+] Q(" << x << ") = " << dt2.tinhGiaTri(x) << "\n";

    cDaThuc tong = dt1.cong(dt2);
    cout << "\n[+] P(x) + Q(x) = ";
    tong.xuat();

    cDaThuc hieu = dt1.tru(dt2);
    cout << "[+] P(x) - Q(x) = ";
    hieu.xuat();

    return 0;
}