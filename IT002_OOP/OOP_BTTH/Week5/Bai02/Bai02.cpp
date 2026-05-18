#include "SachGiaoKhoa.h"
#include "SachThamKhao.h"

int main() {
    SachGiaoKhoa dsSGK[3];
    SachThamKhao dsSTK[3];
    double tongTienSGK = 0;
    double tongTienSTK = 0;
    double tongDonGiaSTK = 0;

    cout << "--- NHAP THONG TIN SACH GIAO KHOA ---" << endl;
    for (int i = 0; i < 3; i++) {
        cout << ">> Cuon thu " << i + 1 << ":" << endl;
        dsSGK[i].Nhap();
        tongTienSGK += dsSGK[i].TinhThanhTien();
    }

    cout << "\n--- NHAP THONG TIN SACH THAM KHAO ---" << endl;
    for (int i = 0; i < 3; i++) {
        cout << ">> Cuon thu " << i + 1 << ":" << endl;
        dsSTK[i].Nhap();
        tongTienSTK += dsSTK[i].TinhThanhTien();
        tongDonGiaSTK += dsSTK[i].getDonGia();
    }

    cout << "\n=============================================" << endl;
    cout << "--- DANH SACH SACH GIAO KHOA ---" << endl;
    for (int i = 0; i < 3; i++) {
        dsSGK[i].Xuat();
    }

    cout << "\n--- DANH SACH SACH THAM KHAO ---" << endl;
    for (int i = 0; i < 3; i++) {
        dsSTK[i].Xuat();
    }

    cout << "\n=============================================" << endl;
    cout << "Tong thanh tien Sach Giao Khoa: " << tongTienSGK << endl;
    cout << "Tong thanh tien Sach Tham Khao: " << tongTienSTK << endl;
    cout << "Trung binh cong don gia Sach Tham Khao: " << tongDonGiaSTK / 3.0 << endl;

    cout << "\n=============================================" << endl;
    string nxbK;
    cout << "Nhap ten NXB can tim (K): ";
    cin.ignore();
    getline(cin, nxbK);

    cout << "\n--- CAC SACH GIAO KHOA CUA NXB " << nxbK << " ---" << endl;
    bool found = false;
    for (int i = 0; i < 3; i++) {
        if (dsSGK[i].getNxb() == nxbK) {
            dsSGK[i].Xuat();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay sach cua nha xuat ban nay!" << endl;
    }

    return 0;
}