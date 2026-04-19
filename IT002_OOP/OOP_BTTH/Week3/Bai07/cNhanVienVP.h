#pragma once

class cNhanVienVP {
private:
    char maNV[20];
    char hoTen[50];
    int ngaySinh;
    int thangSinh;
    int namSinh;
    float luong;

public:
    cNhanVienVP();
    ~cNhanVienVP();

    float getLuong();
    int getNamSinh();
    int getThangSinh();
    int getNgaySinh();

    void setMaNV(const char* ma);
    void setHoTen(const char* ten);
    void setNgaySinh(int d, int m, int y);
    void setLuong(float l);

    void nhap();
    void xuat();
};

class cDSNhanVienVP {
private:
    cNhanVienVP* ds;
    int n;

public:
    cDSNhanVienVP();
    ~cDSNhanVienVP();

    void nhap();
    void xuatDanhSach();
    cNhanVienVP timNhanVienLuongCaoNhat();
    float tinhTongLuong();
    cNhanVienVP timNhanVienTuoiCaoNhat();
    void sapXepLuongTangDan();
};