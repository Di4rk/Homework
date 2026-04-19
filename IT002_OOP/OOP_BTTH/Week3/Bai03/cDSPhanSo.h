#pragma once

struct PhanSo {
    int tu;
    int mau;
};

class cDSPhanSo {
private:
    PhanSo* ds; 
    int n;   

public:
    cDSPhanSo();
    ~cDSPhanSo();

    void nhap();
    void xuat();

    PhanSo tinhTong();
    PhanSo timMax();
    PhanSo timMin();
    PhanSo timPhanSoCoTuLaSNTMax();

    void sapXepTang();
    void sapXepGiam();

    static int gcd(int a, int b);
    static void rutGon(PhanSo& ps);
    static bool laSoNguyenTo(int n);
    static float giaTri(PhanSo ps);
};