#pragma once

class cArray {
private:
    int* arr;
    int n;

    bool laSoNguyenTo(int val);
    void merge(int l, int m, int r);
    void mergeSort(int l, int r);
    void heapify(int size, int i);
    void heapSort();

public:
    cArray();
    ~cArray();

    void taoMangNgauNhien(int size);
    void xuat();
    int demSoLanXuatHien(int x);
    bool kiemTraTangDan();
    int timLeNhoNhat();
    int timSNTLonNhat();

    void sapXepTang();
    void sapXepGiam();
};