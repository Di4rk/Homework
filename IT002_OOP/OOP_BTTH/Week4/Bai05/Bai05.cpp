#include "DaThuc.h"

int main() {
	DaThuc dt1(2), dt2(3);
	cout << "Nhap da thuc 1 (bac 2): ";
	cin >> dt1;
	cout << "Nhap da thuc 2 (bac 3): ";
	cin >> dt2;
	DaThuc sum = dt1 + dt2;
	DaThuc diff = dt1 - dt2;
	cout << "Tong: " << sum << endl;
	cout << "Hieu: " << diff << endl;
	return 0;
}


