#include <iostream>
#include <cmath>
using namespace std;
struct PhanSo {
    int Tu, Mau;
};
int UCLN(int a, int b) {
    return (b == 0) ? abs(a) : UCLN(b, a % b);
}
void Nhap(PhanSo &ps) {
    cin >> ps.Tu >> ps.Mau;
}
PhanSo Nhap() {
    PhanSo ps;
    cin >> ps.Tu >> ps.Mau;
    return ps;
}
PhanSo RutGon(PhanSo ps) {
    int ucln = UCLN(ps.Tu, ps.Mau);
    ps.Tu /= ucln;
    ps.Mau /= ucln;
    if (ps.Mau < 0) {
        ps.Tu = -ps.Tu;
        ps.Mau = -ps.Mau;
    }
    return ps;
}
PhanSo Cong(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.Tu = a.Tu * b.Mau + b.Tu * a.Mau;
    kq.Mau = a.Mau * b.Mau;
    return RutGon(kq);
}
void Xuat(PhanSo ps) {
    if (ps.Mau == 1) cout << ps.Tu;
    else cout << ps.Tu << "/" << ps.Mau;
}

int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    Xuat(Cong(a, b));
    return 0;
}
