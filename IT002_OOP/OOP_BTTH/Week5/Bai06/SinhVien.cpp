#include "SinhVien.h"

void SinhVien::Nhap() {
    cout << "Nhap MSSV: ";
    cin >> maSSV;
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
    cout << "Nhap tong so tin chi: ";
    cin >> tongTinChi;
    cout << "Nhap diem trung binh: ";
    cin >> diemTB;
}

void SinhVien::Xuat() {
    cout << "MSSV: " << maSSV << " | Ho ten: " << hoTen
        << " | Dia chi: " << diaChi << " | Tin chi: " << tongTinChi
        << " | Diem TB: " << diemTB;
}

double SinhVien::getDiemTB() {
    return diemTB;
}