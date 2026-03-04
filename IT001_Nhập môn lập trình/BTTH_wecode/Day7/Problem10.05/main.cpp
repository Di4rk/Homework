#include <iostream>
using namespace std;

struct PhanSo {
    int Tu, Mau;
};

void Nhap(PhanSo &ps) {
    cin >> ps.Tu >> ps.Mau;
}

PhanSo Nhap() {
    PhanSo ps;
    cin >> ps.Tu >> ps.Mau;
    return ps;
}

int SoSanh(PhanSo a, PhanSo b) {
    double giatri1 = (double)a.Tu / a.Mau;
    double giatri2 = (double)b.Tu / b.Mau;
    
    if (giatri1 == giatri2) return 0;
    if (giatri1 > giatri2) return 1;
    return -1;
}

int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    int kq = SoSanh(a, b);
    if (kq == 0)
        std::cout << "Hai phan so bang nhau.";
    else if (kq > 0)
        std::cout << "Phan so thu nhat LON hon phan so thu hai.";
    else
        std::cout << "Phan so thu nhat NHO hon phan so thu hai.";
    return 0;
}
