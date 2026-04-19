#include "cCandidate.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== HE THONG QUAN LY THI SINH ===\n";

    cListCandidate ds;
    ds.nhap();

    cout << "\n[>] Danh sach thi sinh co tong diem > 15:\n";
    ds.xuatLonHon15();

    cout << "\n[>] Thi sinh co tong diem cao nhat (Thu Khoa):\n";
    cCandidate thuKhoa = ds.timThuKhoa();
    thuKhoa.xuat();

    cout << "\n[>] Danh sach sau khi sap xep giam dan theo tong diem:\n";
    ds.sapXepGiamDan();
    ds.xuatTatCa();

    cout << "\n=== HOAN THANH ===\n";
    return 0;
}