#pragma once

class cDaThuc {
private:
    int bac;
    float* heSo;

public:
    cDaThuc();
    cDaThuc(int b);
    cDaThuc(const cDaThuc& other);
    ~cDaThuc();

    void nhap();
    void xuat();
    float tinhGiaTri(float x);
    cDaThuc cong(const cDaThuc& d);
    cDaThuc tru(const cDaThuc& d);
};