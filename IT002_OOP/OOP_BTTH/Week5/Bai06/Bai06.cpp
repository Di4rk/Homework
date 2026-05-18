#include "SVDaiHoc.h"
#include "SVCaoDang.h"

int main() {
    int nDH, nCD;

    cout << "Nhap so luong SV Dai Hoc: ";
    cin >> nDH;
    SVDaiHoc* dsDH = new SVDaiHoc[nDH];
    for (int i = 0; i < nDH; i++) {
        cout << ">> Nhap thong tin SV Dai Hoc thu " << i + 1 << ":" << endl;
        dsDH[i].Nhap();
    }

    cout << "\nNhap so luong SV Cao Dang: ";
    cin >> nCD;
    SVCaoDang* dsCD = new SVCaoDang[nCD];
    for (int i = 0; i < nCD; i++) {
        cout << ">> Nhap thong tin SV Cao Dang thu " << i + 1 << ":" << endl;
        dsCD[i].Nhap();
    }

    cout << "\n=============================================" << endl;
    cout << "--- DANH SACH TAT CA SINH VIEN ---" << endl;
    for (int i = 0; i < nDH; i++) dsDH[i].Xuat();
    for (int i = 0; i < nCD; i++) dsCD[i].Xuat();

    cout << "\n=============================================" << endl;
    cout << "--- DANH SACH SINH VIEN DU DIEU KIEN TOT NGHIEP ---" << endl;
    for (int i = 0; i < nDH; i++) {
        if (dsDH[i].XetTotNghiep()) dsDH[i].Xuat();
    }
    for (int i = 0; i < nCD; i++) {
        if (dsCD[i].XetTotNghiep()) dsCD[i].Xuat();
    }

    cout << "\n=============================================" << endl;
    cout << "--- DANH SACH SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP ---" << endl;
    for (int i = 0; i < nDH; i++) {
        if (!dsDH[i].XetTotNghiep()) dsDH[i].Xuat();
    }
    for (int i = 0; i < nCD; i++) {
        if (!dsCD[i].XetTotNghiep()) dsCD[i].Xuat();
    }

    cout << "\n=============================================" << endl;
    double maxDTB = -1;
    for (int i = 0; i < nDH; i++) {
        if (dsDH[i].getDiemTB() > maxDTB) {
            maxDTB = dsDH[i].getDiemTB();
        }
    }

    if (maxDTB != -1) {
        cout << "--- SINH VIEN DAI HOC CO DIEM TB CAO NHAT ---" << endl;
        for (int i = 0; i < nDH; i++) {
            if (dsDH[i].getDiemTB() == maxDTB) dsDH[i].Xuat();
        }
    }
    else {
        cout << "Khong co sinh vien Dai hoc nao!" << endl;
    }

    delete[] dsDH;
    delete[] dsCD;

    return 0;
}