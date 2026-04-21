#include "CDate.h"

int main() {
	CDate d1, d2;
	cout << "Nhap ngay 1 (Ngay thang nam): \n";
	cin >> d1;
	cout << "Nhap ngay 2 (Ngay thang nam): \n";
	cin >> d2;

	cout << "Ngay 1: " << d1 << endl;
	cout << "Ngay 2: " << d2 << endl;

	int n;
	cout << "Nhap so ngay can cong tru: ";
	cin >> n;

	cout << "Ngay 1 + " << n << " ngay: " << d1 + n << endl;
	cout << "Ngay 1 - " << n << " ngay: " << d1 - n << endl;
	cout << "Ngay 2 - Ngay 1: " << d2 - d1 << " ngay" << endl;

	return 0;
}