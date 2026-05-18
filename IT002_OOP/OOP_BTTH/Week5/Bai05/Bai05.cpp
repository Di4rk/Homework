#include "NVSanXuat.h"
#include "NVVanPhong.h"

int main() {
    int nSX, nVP;

    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> nSX;
    NVSanXuat* dsSX = new NVSanXuat[nSX];
    for (int i = 0; i < nSX; i++) {
        cout << ">> Nhap thong tin NV San Xuat thu " << i + 1 << ":" << endl;
        dsSX[i].Nhap();
        dsSX[i].TinhLuong();
    }

    cout << "\nNhap so luong nhan vien van phong: ";
    cin >> nVP;
    NVVanPhong* dsVP = new NVVanPhong[nVP];
    for (int i = 0; i < nVP; i++) {
        cout << ">> Nhap thong tin NV Van Phong thu " << i + 1 << ":" << endl;
        dsVP[i].Nhap();
        dsVP[i].TinhLuong();
    }

    cout << "\n=============================================" << endl;
    double tongLuongCongTy = 0;

    cout << "--- DANH SACH NHAN VIEN SAN XUAT ---" << endl;
    for (int i = 0; i < nSX; i++) {
        dsSX[i].Xuat();
        tongLuongCongTy += dsSX[i].getLuong();
    }

    cout << "\n--- DANH SACH NHAN VIEN VAN PHONG ---" << endl;
    for (int i = 0; i < nVP; i++) {
        dsVP[i].Xuat();
        tongLuongCongTy += dsVP[i].getLuong();
    }

    cout << "\n=============================================" << endl;
    cout << "TONG LUONG CONG TY PHAI TRA: " << (long long)tongLuongCongTy << " VND" << endl;

    delete[] dsSX;
    delete[] dsVP;

    return 0;
}