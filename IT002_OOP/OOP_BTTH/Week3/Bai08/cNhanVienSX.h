#pragma once

class cNhanVienSX {
private:
    char maNV[20];
    char hoTen[50];
    int ngaySinh;
    int thangSinh;
    int namSinh;
    int soSanPham;
    float donGia;

public:
    cNhanVienSX();
    ~cNhanVienSX();

    float tinhLuong();
    int getNamSinh();
    int getThangSinh();
    int getNgaySinh();

    void setMaNV(const char* ma);
    void setHoTen(const char* ten);
    void setNgaySinh(int d, int m, int y);
    void setSoSanPham(int sp);
    void setDonGia(float gia);

    void nhap();
    void xuat();
};

class cDSNhanVienSX {
private:
    cNhanVienSX* ds;
    int n;

public:
    cDSNhanVienSX();
    ~cDSNhanVienSX();

    void nhap();
    void xuatDanhSach();
    cNhanVienSX timNhanVienLuongThapNhat();
    float tinhTongLuong();
    cNhanVienSX timNhanVienTuoiCaoNhat();
    void sapXepLuongTangDan();
};