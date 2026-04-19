#pragma once

class cCandidate {
private:
    char ma[20];
    char ten[50];
    char ngaySinh[20];
    float diemToan;
    float diemVan;
    float diemAnh;

public:
    cCandidate();
    ~cCandidate();
    void nhap();
    void xuat();
    float tinhTongDiem();
};

class cListCandidate {
private:
    cCandidate* danhSach;
    int n;

public:
    cListCandidate();
    ~cListCandidate();
    void nhap();
    void xuatTatCa();
    void xuatLonHon15();
    cCandidate timThuKhoa();
    void sapXepGiamDan();
};