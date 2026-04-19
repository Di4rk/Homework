#include "cDaGiac.h"
#include <iostream>
#include <cmath>
#include <vector>
#define PI 3.14159265358979323846
using namespace std; 
cDaGiac::cDaGiac() {
    n = 0;
    dinh = nullptr;
}

cDaGiac::cDaGiac(int soDinh) {
    n = soDinh;
    dinh = new cDiem[n];
}

cDaGiac::~cDaGiac() {
    if (dinh != nullptr) {
        delete[] dinh;
    }
}

void cDaGiac::nhap() {
    do {
        cout << "Nhap so dinh cua da giac (n >= 3): ";
        cin >> n;
        if (n < 3) {
            cout << "Da giac phai co it nhat 3 dinh. Vui long nhap lai!" << endl;
        }
    } while (n < 3);

    if (dinh != nullptr) {
        delete[] dinh;
    }
    dinh = new cDiem[n];

    cout << "--- Nhap toa do cac dinh ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Dinh " << i + 1 << " (x y): ";
        cin >> dinh[i].x >> dinh[i].y;
    }
}

void cDaGiac::xuat() const {
    cout << "Da giac co " << n << " dinh: ";
    for (int i = 0; i < n; i++) {
        cout << "(" << dinh[i].x << ", " << dinh[i].y << ") ";
    }
    cout << endl;
}

float khoangCach(cDiem A, cDiem B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

float cDaGiac::tinhChuVi() const {
    if (n < 3) return 0;
    float chuVi = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        chuVi += khoangCach(dinh[i], dinh[next]);
    }
    return chuVi;
}

float cDaGiac::tinhDienTich() const {
    if (n < 3) return 0;
    float dienTich = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        dienTich += (dinh[i].x * dinh[next].y) - (dinh[next].x * dinh[i].y);
    }
    return abs(dienTich) / 2.0;
}

void cDaGiac::tinhTien(float dx, float dy) {
    for (int i = 0; i < n; i++) {
        dinh[i].x += dx;
        dinh[i].y += dy;
    }
}

void cDaGiac::quay(float gocDo) {
    float rad = gocDo * PI / 180.0;
    float cosGoc = cos(rad);
    float sinGoc = sin(rad);

    for (int i = 0; i < n; i++) {
        float xMoi = dinh[i].x * cosGoc - dinh[i].y * sinGoc;
        float yMoi = dinh[i].x * sinGoc + dinh[i].y * cosGoc;
        dinh[i].x = xMoi;
        dinh[i].y = yMoi;
    }
}

void cDaGiac::phongTo(float k) {
    for (int i = 0; i < n; i++) {
        dinh[i].x *= k;
        dinh[i].y *= k;
    }
}

void cDaGiac::thuNho(float k) {
    if (k == 0) {
        cout << "He so thu nho khong duoc bang 0!" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        dinh[i].x /= k;
        dinh[i].y /= k;
    }
}