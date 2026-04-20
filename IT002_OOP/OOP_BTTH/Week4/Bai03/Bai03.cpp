#include "CTime.h"
#include <iomanip>

int main() {
	CTime t1, t2;
	cout << "Nhap thoi gian 1 (Gio Phut Giay): ";
	cin >> t1;
	cout << "Nhap thoi gian 2 (Gio Phut Giay): ";
	cin >> t2;
	cout << "Thoi gian 1: " << t1 << endl;
	cout << "Thoi gian 2: " << t2 << endl;
	int giay = 5000; 
	cout << "Thoi gian 1 + " << giay << " giay: " << t1 + giay << endl;
	cout << "Thoi gian 2 - " << giay << " giay: " << t2 - giay << endl;
	cout << "Thoi gian 1 sau khi tang 1 giay: " << ++t1 << endl;
	cout << "Thoi gian 2 sau khi giam 1 giay: " << --t2 << endl;
	return 0;
}