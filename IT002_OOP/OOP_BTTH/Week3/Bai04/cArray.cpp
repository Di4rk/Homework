#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

cArray::cArray() {
    arr = nullptr;
    n = 0;
}

cArray::~cArray() {
    if (arr != nullptr) {
        delete[] arr;
    }
}

void cArray::taoMangNgauNhien(int size) {
    if (arr != nullptr) {
        delete[] arr;
    }
    n = size;
    arr = new int[n];
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100;
    }
}

void cArray::xuat() {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int cArray::demSoLanXuatHien(int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}

bool cArray::kiemTraTangDan() {
    if (n < 2) return true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] >= arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int cArray::timLeNhoNhat() {
    int minLe = 1e9;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            if (arr[i] < minLe) {
                minLe = arr[i];
                found = true;
            }
        }
    }
    if (!found) return 1e9;
    return minLe;
}

bool cArray::laSoNguyenTo(int val) {
    if (val < 2) return false;
    for (int i = 2; i <= sqrt(val); i++) {
        if (val % i == 0) return false;
    }
    return true;
}

int cArray::timSNTLonNhat() {
    int maxSNT = -1e9;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {
            if (arr[i] > maxSNT) {
                maxSNT = arr[i];
                found = true;
            }
        }
    }
    if (!found) return -1e9;
    return maxSNT;
}

void cArray::merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void cArray::mergeSort(int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(l, m);
    mergeSort(m + 1, r);
    merge(l, m, r);
}

void cArray::sapXepTang() {
    if (n > 1) {
        mergeSort(0, n - 1);
    }
}

void cArray::heapify(int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] < arr[smallest]) smallest = l;
    if (r < size && arr[r] < arr[smallest]) smallest = r;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(size, smallest);
    }
}

void cArray::heapSort() {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(i, 0);
    }
}

void cArray::sapXepGiam() {
    if (n > 1) {
        heapSort();
    }
}