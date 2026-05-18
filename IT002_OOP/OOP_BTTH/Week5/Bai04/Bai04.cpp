#include "GDDat.h"
#include "GDNhaPho.h"
#include "GDChungCu.h"

bool checkThang12Nam2024(string ngay) {
    if (ngay.length() >= 7) {
        string thangNam = ngay.substr(ngay.length() - 7);
        return (thangNam == "12/2024");
    }
    return false;
}

int main() {
    int slDat, slNhaPho, slChungCu;

    cout << "Nhap so luong giao dich Dat: ";
    cin >> slDat;
    GDDat* dsDat = new GDDat[slDat];
    for (int i = 0; i < slDat; i++) {
        cout << ">> Giao dich Dat thu " << i + 1 << ":" << endl;
        dsDat[i].Nhap();
    }

    cout << "\nNhap so luong giao dich Nha Pho: ";
    cin >> slNhaPho;
    GDNhaPho* dsNhaPho = new GDNhaPho[slNhaPho];
    for (int i = 0; i < slNhaPho; i++) {
        cout << ">> Giao dich Nha Pho thu " << i + 1 << ":" << endl;
        dsNhaPho[i].Nhap();
    }

    cout << "\nNhap so luong giao dich Chung Cu: ";
    cin >> slChungCu;
    GDChungCu* dsChungCu = new GDChungCu[slChungCu];
    double tongTienCC = 0;
    for (int i = 0; i < slChungCu; i++) {
        cout << ">> Giao dich Chung Cu thu " << i + 1 << ":" << endl;
        dsChungCu[i].Nhap();
        tongTienCC += dsChungCu[i].TinhThanhTien();
    }

    cout << "\n=============================================" << endl;
    cout << "Tong so luong GD Dat: " << slDat << endl;
    cout << "Tong so luong GD Nha Pho: " << slNhaPho << endl;
    cout << "Tong so luong GD Chung Cu: " << slChungCu << endl;

    if (slChungCu > 0) {
        cout << "Trung binh thanh tien GD Chung Cu: " << tongTienCC / slChungCu << endl;
    }
    else {
        cout << "Khong co GD Chung Cu nao de tinh trung binh." << endl;
    }

    cout << "\n=============================================" << endl;
    double maxTienNhaPho = -1;
    for (int i = 0; i < slNhaPho; i++) {
        if (dsNhaPho[i].TinhThanhTien() > maxTienNhaPho) {
            maxTienNhaPho = dsNhaPho[i].TinhThanhTien();
        }
    }

    if (maxTienNhaPho != -1) {
        cout << "--- CAC GIAO DICH NHA PHO CO TRI GIA CAO NHAT ---" << endl;
        for (int i = 0; i < slNhaPho; i++) {
            if (dsNhaPho[i].TinhThanhTien() == maxTienNhaPho) {
                dsNhaPho[i].Xuat();
            }
        }
    }

    cout << "\n=============================================" << endl;
    cout << "--- DANH SACH GIAO DICH THANG 12 NAM 2024 ---" << endl;
    bool coGD = false;
    for (int i = 0; i < slDat; i++) {
        if (checkThang12Nam2024(dsDat[i].getNgayGD())) {
            dsDat[i].Xuat();
            coGD = true;
        }
    }
    for (int i = 0; i < slNhaPho; i++) {
        if (checkThang12Nam2024(dsNhaPho[i].getNgayGD())) {
            dsNhaPho[i].Xuat();
            coGD = true;
        }
    }
    for (int i = 0; i < slChungCu; i++) {
        if (checkThang12Nam2024(dsChungCu[i].getNgayGD())) {
            dsChungCu[i].Xuat();
            coGD = true;
        }
    }
    if (!coGD) {
        cout << "Khong co giao dich nao trong thang 12/2024!" << endl;
    }

    delete[] dsDat;
    delete[] dsNhaPho;
    delete[] dsChungCu;

    return 0;
}