#include <bits/stdc++.h>
using namespace std;
struct PhanSo {
    int tu;
    int mau;
};
int timUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0) return a + b;
    while (a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}
void nhapPhanSo(PhanSo &ps) {
    cout << "Nhap tu so: "; 
    cin >> ps.tu;
    cout << "Nhap mau so: "; 
    cin >> ps.mau;
}
void xuatPhanSo(PhanSo ps) {
    if (ps.mau == 1) cout << ps.tu; 
    else cout << ps.tu << "/" << ps.mau;
}
PhanSo rutGon(PhanSo ps) {
    int ucln = timUCLN(ps.tu, ps.mau);
    ps.tu = ps.tu / ucln;
    ps.mau = ps.mau / ucln;
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    return ps;
}
PhanSo timMax(PhanSo ps1, PhanSo ps2) {
    float giaTri1 = (float)ps1.tu / ps1.mau;
    float giaTri2 = (float)ps2.tu / ps2.mau;
    if (giaTri1 > giaTri2) return ps1;
    else return ps2;
}
PhanSo cong(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = (ps1.tu * ps2.mau) + (ps2.tu * ps1.mau);
    kq.mau = ps1.mau * ps2.mau;
    return rutGon(kq);
}
PhanSo tru(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = (ps1.tu * ps2.mau) - (ps2.tu * ps1.mau);
    kq.mau = ps1.mau * ps2.mau;
    return rutGon(kq);
}
PhanSo nhan(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    return rutGon(kq);
}
PhanSo chia(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau;
    kq.mau = ps1.mau * ps2.tu;
    return rutGon(kq);
}
int main() {
    PhanSo p1, p2;
    cout << "Nhap phan so thu 1:\n";
    nhapPhanSo(p1);
    cout << "\nNhap phan so thu 2:\n";
    nhapPhanSo(p2);    
    cout << "\nKet qua:\n";
    cout << "1. Phan so 1 sau khi rut gon: ";
    xuatPhanSo(rutGon(p1));
    cout << "\n   Phan so 2 sau khi rut gon: ";
    xuatPhanSo(rutGon(p2));    
    cout << "\n\n2. Phan so lon nhat la: ";
    xuatPhanSo(timMax(p1, p2));   
    cout << "\n\n3. Phep tinh giua 2 phan so:\n";
    cout << "   - Tong: "; xuatPhanSo(cong(p1, p2)); cout << "\n";
    cout << "   - Hieu: "; xuatPhanSo(tru(p1, p2)); cout << "\n";
    cout << "   - Tich: "; xuatPhanSo(nhan(p1, p2)); cout << "\n";
    cout << "   - Thuong: "; xuatPhanSo(chia(p1, p2)); cout << "\n";    
    return 0;
}