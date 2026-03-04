#include <iostream>
#include <cmath>
using namespace std;
class PhanSo {
private:
    int tu;
    int mau;    
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
public:
    PhanSo() { tu = 0; mau = 1; }
    void nhap() {
        cout << "Nhap tu so: "; cin >> tu;
        cout << "Nhap mau so: "; cin >> mau;
    }
    void xuat() {
        if (mau == 1) cout << tu;
        else cout << tu << "/" << mau;
    }
    void rutGon() {
        int ucln = timUCLN(tu, mau);
        tu /= ucln;
        mau /= ucln;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }
    PhanSo timMax(PhanSo psKhac) {
        float gt1 = (float)tu / mau;
        float gt2 = (float)psKhac.tu / psKhac.mau;
        if (gt1 > gt2) return *this;
        return psKhac;
    }
    PhanSo cong(PhanSo psKhac) {
        PhanSo kq;
        kq.tu = tu * psKhac.mau + psKhac.tu * mau;
        kq.mau = mau * psKhac.mau;
        kq.rutGon();
        return kq;
    }
    PhanSo tru(PhanSo psKhac) {
        PhanSo kq;
        kq.tu = tu * psKhac.mau - psKhac.tu * mau;
        kq.mau = mau * psKhac.mau;
        kq.rutGon();
        return kq;
    }
    PhanSo nhan(PhanSo psKhac) {
        PhanSo kq;
        kq.tu = tu * psKhac.tu;
        kq.mau = mau * psKhac.mau;
        kq.rutGon();
        return kq;
    }
    PhanSo chia(PhanSo psKhac) {
        PhanSo kq;
        kq.tu = tu * psKhac.mau;
        kq.mau = mau * psKhac.tu;
        kq.rutGon();
        return kq;
    }
};
int main() {
    PhanSo p1, p2;
    cout << "Nhap phan so 1: \n"; 
    p1.nhap(); 
    p1.rutGon();
    cout << "Nhap phan so 2: \n"; 
    p2.nhap(); 
    p2.rutGon();    
    cout << "\nKet uqa: \n";
    cout << "Tong: "; 
    p1.cong(p2).xuat(); 
    cout << "\n";
    cout << "Hieu: "; 
    p1.tru(p2).xuat(); 
    cout << "\n";
    cout << "Tich: "; 
    p1.nhan(p2).xuat(); 
    cout << "\n";
    cout << "Thuong: "; 
    p1.chia(p2).xuat();
     cout << "\n";
    cout << "Lon nhat: "; 
    p1.timMax(p2).xuat(); 
    cout << "\n";
    return 0;
}