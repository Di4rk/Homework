#include <iostream>
#include <cmath>
using namespace std;

#define MAXN 100
struct PhanSo {
    int Tu, Mau;
};
int UCLN(int a, int b) {
    return (b == 0) ? abs(a) : UCLN(b, a % b);
}
void Nhap(PhanSo a[], int &n) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].Tu >> a[i].Mau;
    }
}
void Xuat(PhanSo a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i].Mau == 0) {
            cout << "Khong thoa yeu cau bai toan" << endl;
        } else {
            if (a[i].Mau < 0) {
                a[i].Tu = -a[i].Tu;
                a[i].Mau = -a[i].Mau;
            }
            int ucln = UCLN(a[i].Tu, a[i].Mau);
            a[i].Tu /= ucln;
            a[i].Mau /= ucln;
            if (a[i].Mau == 1) cout << a[i].Tu << endl;
            else cout << a[i].Tu << "/" << a[i].Mau << endl;
        }
    }
}

int main() {
    PhanSo a[MAXN];
    int n;
    Nhap(a, n);
    Xuat(a, n);
    return 0;
}

