#include <iostream>
#include <climits> 
#include <cstdlib> 
#include <ctime>   

using namespace std;

class cArray {
private:
    int* arr;
    int size;

public:
    cArray();
    ~cArray();

    void Nhap();
    void DaySoNgauNhien();
    void Xuat();

    int Check(int x);
    bool KiemTraTangDan();
    void PhanTuChanLeNhoNhat();
    void SapXepTangDan();
};

cArray::cArray() {
    arr = nullptr;
    size = 0;
}

cArray::~cArray() {
    delete[] arr;
}

void cArray::Nhap() {
    cout << "Nhap so luong phan tu: ";
    cin >> size;

    if (arr != nullptr) delete[] arr;
    arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void cArray::Xuat() {
    if (size == 0) {
        cout << "Mang rong!" << endl;
        return;
    }
    cout << "Cac phan tu trong mang: ";

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void cArray::DaySoNgauNhien() {
    cout << "Nhap so luong phan tu: ";
    cin >> size;

    if (arr != nullptr) delete[] arr;
    arr = new int[size];
}

int cArray::Check(int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}

bool cArray::KiemTraTangDan() {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void cArray::PhanTuChanLeNhoNhat() {
    int minEven = INT_MAX;
    int minOdd = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && arr[i] < minEven) {
            minEven = arr[i];
        }
        if (arr[i] % 2 != 0 && arr[i] < minOdd) {
            minOdd = arr[i];
        }
    }

    if (minEven != INT_MAX) cout << "Phan tu chan nho nhat: " << minEven << endl;
    else cout << "Khong co phan tu chan." << endl;

    if (minOdd != INT_MAX) cout << "Phan tu le nho nhat: " << minOdd << endl;
    else cout << "Khong co phan tu le." << endl;
}

void cArray::SapXepTangDan() {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    cArray a;

    a.Nhap();
    a.Xuat();
    a.PhanTuChanLeNhoNhat();
    cout << "Dang sap xep mang..." << endl;
    a.SapXepTangDan();
    a.Xuat();
    return 0;
}