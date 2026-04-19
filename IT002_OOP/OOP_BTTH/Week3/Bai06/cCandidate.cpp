#include "cCandidate.h"
#include <iostream>

using namespace std;

cCandidate::cCandidate() {
    ma[0] = '\0';
    ten[0] = '\0';
    ngaySinh[0] = '\0';
    diemToan = 0;
    diemVan = 0;
    diemAnh = 0;
}

cCandidate::~cCandidate() {}

void cCandidate::nhap() {
    cout << "Nhap ma thi sinh: ";
    cin >> ws;
    cin.getline(ma, 20);

    cout << "Nhap ten thi sinh: ";
    cin.getline(ten, 50);

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    cin.getline(ngaySinh, 20);

    cout << "Nhap diem Toan, Van, Anh: ";
    cin >> diemToan >> diemVan >> diemAnh;
}

void cCandidate::xuat() {
    cout << "Ma: " << ma << " | Ten: " << ten << " | NS: " << ngaySinh
        << " | Toan: " << diemToan << " | Van: " << diemVan << " | Anh: " << diemAnh
        << " | Tong diem: " << tinhTongDiem() << "\n";
}

float cCandidate::tinhTongDiem() {
    return diemToan + diemVan + diemAnh;
}

cListCandidate::cListCandidate() {
    danhSach = nullptr;
    n = 0;
}

cListCandidate::~cListCandidate() {
    if (danhSach != nullptr) {
        delete[] danhSach;
    }
}

void cListCandidate::nhap() {
    cout << "Nhap so luong thi sinh: ";
    cin >> n;

    if (danhSach != nullptr) {
        delete[] danhSach;
    }
    danhSach = new cCandidate[n];

    for (int i = 0; i < n; i++) {
        cout << "--- Nhap thong tin thi sinh thu " << i + 1 << " ---\n";
        danhSach[i].nhap();
    }
}

void cListCandidate::xuatTatCa() {
    for (int i = 0; i < n; i++) {
        danhSach[i].xuat();
    }
}

void cListCandidate::xuatLonHon15() {
    bool coThiSinh = false;
    for (int i = 0; i < n; i++) {
        if (danhSach[i].tinhTongDiem() > 15.0f) {
            danhSach[i].xuat();
            coThiSinh = true;
        }
    }
    if (!coThiSinh) {
        cout << "Khong co thi sinh nao co tong diem lon hon 15.\n";
    }
}

cCandidate cListCandidate::timThuKhoa() {
    if (n == 0) return cCandidate();
    cCandidate thuKhoa = danhSach[0];
    for (int i = 1; i < n; i++) {
        if (danhSach[i].tinhTongDiem() > thuKhoa.tinhTongDiem()) {
            thuKhoa = danhSach[i];
        }
    }
    return thuKhoa;
}

void cListCandidate::sapXepGiamDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (danhSach[i].tinhTongDiem() < danhSach[j].tinhTongDiem()) {
                cCandidate temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}