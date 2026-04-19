#pragma once

struct cDiem {
    float x;
    float y;
};

class cDaGiac {
private:
    int n;          
    cDiem* dinh;    

public:
    cDaGiac();
    cDaGiac(int soDinh);
    ~cDaGiac();

    void nhap();
    void xuat() const;

    float tinhChuVi() const;
    float tinhDienTich() const;

    void tinhTien(float dx, float dy);
    void quay(float gocDo);
    void phongTo(float k);
    void thuNho(float k);
};