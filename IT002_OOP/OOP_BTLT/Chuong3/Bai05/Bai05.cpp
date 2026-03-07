#include <iostream>
#include <vector>
using namespace std;

class cArray {
private:
	int n;
	vector<int> arr;
public:
	void Nhap();
	void Xuat();
	int SoAmLonNhat();
	int DemSoLanXuatHien(int x);
	bool KiemTraMangGiamDan();
	void SapXepMangTangDan();
};

void cArray::Nhap() {
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> arr[i];
	}
}

void cArray::Xuat() {
	cout << "Cac phan tu trong mang: [ ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}

int cArray::SoAmLonNhat() {
	int maxAm = INT_MIN;
	bool foundAm = false;
	for (int i = 1; i < n; i++) {
		if (arr[i] < 0 && arr[i] > maxAm) {
			maxAm = arr[i];
			foundAm = true;
		}
	}
return (foundAm) ? maxAm : 0;
}

int cArray::DemSoLanXuatHien(int x) {
	int count = 0;
	for (int i : arr) {
		if (i == x) {
			count++;
		}
	}
	return count;
}

bool cArray::KiemTraMangGiamDan() {
	for (int i : arr) {
		if (i < arr[i + 1]) {
			return false;
		}
	}
	return true;
}

void cArray::SapXepMangTangDan() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
		cArray myArray;
	myArray.Nhap();
	myArray.Xuat();
	cout << "So am lon nhat trong mang: " << myArray.SoAmLonNhat() << endl;
	int x;
	cout << "Nhap gia tri can dem so lan xuat hien: ";
	cin >> x;
	cout << "So lan xuat hien cua " << x << ": " << myArray.DemSoLanXuatHien(x) << endl;
	if (myArray.KiemTraMangGiamDan()) {
		cout << "Mang giam dan." << endl;
	} else {
		cout << "Mang khong giam dan." << endl;
	}
	myArray.SapXepMangTangDan();
	cout << "Mang sau khi sap xep tang dan: ";
	myArray.Xuat();
	return 0;
}