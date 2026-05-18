#include "NoiThanh.h"
#include "NgoaiThanh.h"

int main() {
    NoiThanh dsNoiThanh[2];
    NgoaiThanh dsNgoaiThanh[2];
    double tongDoanhThuNoi = 0;
    double tongDoanhThuNgoai = 0;

    cout << "--- NHAP THONG TIN CHUYEN XE NOI THANH ---" << endl;
    for (int i = 0; i < 2; i++) {
        cout << ">> Chuyen xe noi thanh thu " << i + 1 << ":" << endl;
        dsNoiThanh[i].Nhap();
        tongDoanhThuNoi += dsNoiThanh[i].getDoanhThu();
    }

    cout << "\n--- NHAP THONG TIN CHUYEN XE NGOAI THANH ---" << endl;
    for (int i = 0; i < 2; i++) {
        cout << ">> Chuyen xe ngoai thanh thu " << i + 1 << ":" << endl;
        dsNgoaiThanh[i].Nhap();
        tongDoanhThuNgoai += dsNgoaiThanh[i].getDoanhThu();
    }

    cout << "\n=============================================" << endl;
    cout << "--- DANH SACH CHUYEN XE NOI THANH ---" << endl;
    for (int i = 0; i < 2; i++) {
        dsNoiThanh[i].Xuat();
    }

    cout << "\n--- DANH SACH CHUYEN XE NGOAI THANH ---" << endl;
    for (int i = 0; i < 2; i++) {
        dsNgoaiThanh[i].Xuat();
    }

    cout << "\n=============================================" << endl;
    cout << "Tong doanh thu chuyen xe noi thanh: " << tongDoanhThuNoi << endl;
    cout << "Tong doanh thu chuyen xe ngoai thanh: " << tongDoanhThuNgoai << endl;
    cout << "TONG DOANH THU TAT CA CHUYEN XE: " << tongDoanhThuNoi + tongDoanhThuNgoai << endl;

    return 0;
}