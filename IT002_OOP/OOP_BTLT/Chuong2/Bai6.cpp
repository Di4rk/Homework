#include <iostream>
#include <string>
using namespace std;
class Ngay {
public:
    int d, m, y;
    void nhap() {
        cout << "Nhap ngay/thang/nam sinh: ";
        cin >> d >> m >> y;
    }
    void xuat() {
        cout << d << "/" << m << "/" << y;
    }
    bool nhoTuoiHon(Ngay ngKhac) {
        if (y != ngKhac.y) return y > ngKhac.y;
        if (m != ngKhac.m) return m > ngKhac.m;
        return d > ngKhac.d;
    }
};
class NhanVien {
private:
    string maNV, hoTen, gioiTinh;
    Ngay ngaySinh;
public:
    void nhap() {
        cout << "Nhap ma NV: "; cin >> maNV;
        cin.ignore();
        cout << "Nhap ho ten: "; getline(cin, hoTen);
        cout << "Nhap gioi tinh: "; cin >> gioiTinh;
        ngaySinh.nhap();
    }
    void xuat() {
        cout << maNV << " - " << hoTen << " - " << gioiTinh << " - NS: ";
        ngaySinh.xuat(); cout << "\n";
    }
    bool nhoTuoiHon(NhanVien nvKhac) {
        return ngaySinh.nhoTuoiHon(nvKhac.ngaySinh);
    }
};
int main() {
    NhanVien nv1, nv2;
    cout << "Nhan vien 1:\n"; nv1.nhap();
    cout << "Nhan vien 2:\n"; nv2.nhap();
    cout << "\n=> Nhan vien nho tuoi hon la:\n";
    if (nv1.nhoTuoiHon(nv2)) nv1.xuat();
    else nv2.xuat();    
    return 0;
}