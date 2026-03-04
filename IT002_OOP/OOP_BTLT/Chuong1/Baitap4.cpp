#include <bits/stdc++.h>
using namespace std;
struct Ngay {
    int d;
    int m;
    int y;
};
struct HocSinh {
    string hoTen;
    float diemToan;
    float diemVan;
};
bool kiemTraNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}
int laySoNgay(int thang, int nam) {
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return 30;
    } else if (thang == 2) {
        if (kiemTraNamNhuan(nam)) return 29;
        else return 28;
    } else {
        return 31;
    }
}
void nhapNgay(Ngay &ng) {
    cout << "Nhap ngay: "; cin >> ng.d;
    cout << "Nhap thang: "; cin >> ng.m;
    cout << "Nhap nam: "; cin >> ng.y;
}
void xuatNgay(Ngay ng) {
    cout << ng.d << "/" << ng.m << "/" << ng.y;
}
Ngay timNgayKeTiep(Ngay ng) {
    Ngay kq = ng;
    int soNgayTrongThang = laySoNgay(kq.m, kq.y);
    kq.d++;
    if (kq.d > soNgayTrongThang) {
        kq.d = 1;
        kq.m++;
        if (kq.m > 12) {
            kq.m = 1;
            kq.y++;
        }
    }
    return kq;
}
void nhapHocSinh(HocSinh &hs) {
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hs.hoTen);
    cout << "Nhap diem Toan: "; cin >> hs.diemToan;
    cout << "Nhap diem Van: "; cin >> hs.diemVan;
}
void xuatHocSinh(HocSinh hs) {
    cout << "Ho ten: " << hs.hoTen << "\n";
    cout << "Diem Toan: " << hs.diemToan << "\n";
    cout << "Diem Van: " << hs.diemVan << "\n";
    float dtb = (hs.diemToan + hs.diemVan) / 2.0;
    cout << "Diem trung binh: " << dtb << "\n";
}
int main() {
    Ngay ng;
    cout << "Tim ngay ke tiep: \n";
    nhapNgay(ng);
    cout << "Ngay vua nhap: "; xuatNgay(ng); cout << "\n";
    cout << "Ngay ke tiep la: "; xuatNgay(timNgayKeTiep(ng)); cout << "\n";
    
    HocSinh hs;
    cout << "\nTinh diem hoc sinh: \n";
    nhapHocSinh(hs);
    cout << "\nKet qua:\n";
    xuatHocSinh(hs);
    
    return 0;
}