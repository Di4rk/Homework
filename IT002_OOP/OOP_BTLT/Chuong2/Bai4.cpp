#include <iostream>
#include <string>
using namespace std;
class Ngay {
private:
    int d, m, y;
    bool kiemTraNamNhuan(int nam) {
        return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
    }
    int laySoNgayTrongThang(int thang, int nam) {
        if (thang == 4 || thang == 6 || thang == 9 || thang == 11) return 30;
        if (thang == 2) return kiemTraNamNhuan(nam) ? 29 : 28;
        return 31;
    }
public:
    void nhap() {
        cout << "Nhap ngay/thang/nam: ";
        cin >> d >> m >> y;
    }
    void xuat() {
        cout << d << "/" << m << "/" << y;
    }
    Ngay timNgayKeTiep() {
        Ngay kq = *this;
        int soNgayThang = laySoNgayTrongThang(kq.m, kq.y);
        kq.d++;
        if (kq.d > soNgayThang) {
            kq.d = 1; kq.m++;
            if (kq.m > 12) { kq.m = 1; kq.y++; }
        }
        return kq;
    }
};
class HocSinh {
private:
    string maHS, hoTen;
    float diemToan, diemVan;
public:
    void nhap() {
        cout << "Nhap ma HS: "; cin >> maHS;
        cin.ignore();
        cout << "Nhap ho ten: "; getline(cin, hoTen);
        cout << "Nhap diem Toan, Van: "; cin >> diemToan >> diemVan;
    }
    void xuat() {
        cout << "HS: " << maHS << " - " << hoTen << " | Toan: " << diemToan << " | Van: " << diemVan << " | DTB: " << tinhDTB() << "\n";
    }
    float tinhDTB() {
        return (diemToan + diemVan) / 2.0;
    }
};
int main() {
    cout << "a) Ngay: \n";
    Ngay ng; ng.nhap();
    cout << "Ngay ke tiep la: "; ng.timNgayKeTiep().xuat(); cout << "\n\n";
    cout << "b) Hoc sinh: \n";
    HocSinh hs; hs.nhap();
    cout << "\nThong tin hoc sinh:\n"; hs.xuat();
    return 0;
}