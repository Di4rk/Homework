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
};
class SinhVien {
private:
    string maSV, hoTen;
    Ngay ngaySinh;
    float dtb;
public:
    void nhap() {
        cout << "Nhap ma SV: "; cin >> maSV;
        cin.ignore();
        cout << "Nhap ho ten: "; getline(cin, hoTen);
        ngaySinh.nhap();
        cout << "Nhap diem trung binh: "; cin >> dtb;
    }
    void xuat() {
        cout << maSV << " - " << hoTen << " - NS: ";
        ngaySinh.xuat();
        cout << " - DTB: " << dtb << "\n";
    }
    float getDTB() {
        return dtb;
    }
};
int main() {
    SinhVien sv1, sv2;
    cout << "SV1: \n"; sv1.nhap();
    cout << "SV2: \n"; sv2.nhap();
    cout << "\n=> Sinh vien co DTB nho hon la:\n";
    if (sv1.getDTB() < sv2.getDTB()) sv1.xuat();
    else if (sv1.getDTB() > sv2.getDTB()) sv2.xuat();
    else {
        cout << "Hai sinh vien co DTB bang nhau.\n";
    }
    return 0;
}