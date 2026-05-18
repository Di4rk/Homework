#include "SVCaoDang.h"

void SVCaoDang::Nhap() {
    SinhVien::Nhap();
    cout << "Nhap diem thi tot nghiep: ";
    cin >> diemThiTN;
}

void SVCaoDang::Xuat() {
    SinhVien::Xuat();
    cout << " | Diem thi TN: " << diemThiTN << " | He: Cao Dang" << endl;
}

bool SVCaoDang::XetTotNghiep() {
    return (tongTinChi >= 110 && diemTB >= 5.0 && diemThiTN >= 5.0);
}