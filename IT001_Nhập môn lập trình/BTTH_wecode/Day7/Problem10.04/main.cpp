
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
void Nhap(char hoTen[]) {
    cin.getline(hoTen, 100);
}
void Nhap(SinhVien A[], int &n) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin.getline(A[i].MASV, 10);
        cin.getline(A[i].HoTen, 100);
        cin.getline(A[i].NgaySinh, 12);
        cin >> A[i].GioiTinh;
        cin >> A[i].DiemToan >> A[i].DiemLy >> A[i].DiemHoa;
        A[i].DTB = (A[i].DiemToan + A[i].DiemLy + A[i].DiemHoa) / 3;
    }
}
void XoaTheoHoTen(SinhVien A[], int &n, char hoTen[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(A[i].HoTen, hoTen) == 0) {
            for (int j = i; j < n - 1; j++) {
                A[j] = A[j + 1];
            }
            n--;
            i--;
        }
    }
}
void Xuat(SinhVien A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i].MASV << "\t"
             << A[i].HoTen << "\t"
             << A[i].NgaySinh << "\t"
             << A[i].GioiTinh << "\t"
             << A[i].DiemToan << "\t"
             << A[i].DiemLy << "\t"
             << A[i].DiemHoa << "\t"
             << setprecision(3) << A[i].DTB << endl;
    }
}
int main() {
    SinhVien A[MAXN];
    char hoTenCanXoa[100];
    int n;

    Nhap(hoTenCanXoa);

    Nhap(A, n);

    XoaTheoHoTen(A, n, hoTenCanXoa);

    Xuat(A, n);
    return 0;
}
