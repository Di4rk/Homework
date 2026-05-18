#include "GiaoDichVang.h"
#include "GiaoDichTienTe.h"

int main() {
    int n, m;
    cout << "Nhap so luong giao dich Vang: ";
    cin >> n;
    GiaoDichVang* dsVang = new GiaoDichVang[n];

    for (int i = 0; i < n; i++) {
        cout << ">> Nhap thong tin GD Vang thu " << i + 1 << ":" << endl;
        dsVang[i].Nhap();
    }

    cout << "\nNhap so luong giao dich Tien Te: ";
    cin >> m;
    GiaoDichTienTe* dsTienTe = new GiaoDichTienTe[m];

    for (int i = 0; i < m; i++) {
        cout << ">> Nhap thong tin GD Tien Te thu " << i + 1 << ":" << endl;
        dsTienTe[i].Nhap();
    }

    cout << "\n=============================================" << endl;
    double maxTienVang = -1;
    for (int i = 0; i < n; i++) {
        if (dsVang[i].TinhThanhTien() > maxTienVang) {
            maxTienVang = dsVang[i].TinhThanhTien();
        }
    }

    if (maxTienVang != -1) {
        cout << "--- CAC GIAO DICH VANG CO THANH TIEN CAO NHAT ---" << endl;
        for (int i = 0; i < n; i++) {
            if (dsVang[i].TinhThanhTien() == maxTienVang) {
                dsVang[i].Xuat();
            }
        }
    }

    cout << "\n=============================================" << endl;
    double minTienEuro = -1;
    for (int i = 0; i < m; i++) {
        if (dsTienTe[i].getLoaiTien() == 3) {
            if (minTienEuro == -1 || dsTienTe[i].TinhThanhTien() < minTienEuro) {
                minTienEuro = dsTienTe[i].TinhThanhTien();
            }
        }
    }

    if (minTienEuro != -1) {
        cout << "--- CAC GIAO DICH EURO CO THANH TIEN THAP NHAT ---" << endl;
        for (int i = 0; i < m; i++) {
            if (dsTienTe[i].getLoaiTien() == 3 && dsTienTe[i].TinhThanhTien() == minTienEuro) {
                dsTienTe[i].Xuat();
            }
        }
    }
    else {
        cout << "Khong co giao dich Euro nao!" << endl;
    }

    cout << "\n=============================================" << endl;
    cout << "--- CAC GIAO DICH CO THANH TIEN TREN 1 TY ---" << endl;
    bool coGD1Ty = false;
    for (int i = 0; i < n; i++) {
        if (dsVang[i].TinhThanhTien() > 1000000000) {
            dsVang[i].Xuat();
            coGD1Ty = true;
        }
    }
    for (int i = 0; i < m; i++) {
        if (dsTienTe[i].TinhThanhTien() > 1000000000) {
            dsTienTe[i].Xuat();
            coGD1Ty = true;
        }
    }
    if (!coGD1Ty) {
        cout << "Khong co giao dich nao tren 1 ty dong!" << endl;
    }

    delete[] dsVang;
    delete[] dsTienTe;

    return 0;
}