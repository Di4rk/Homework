#include "SoPhuc.h"
#include <iostream>
using namespace std;


int main() {
	SoPhuc sp1, sp2;
	cout << "Nhap so phuc 1 (thuc ao): ";
	cin >> sp1;
	cout << "Nhap so phuc 2 (thuc ao): ";
	cin >> sp2;
	cout << "So phuc 1: " << sp1 << endl;
	cout << "So phuc 2: " << sp2 << endl;
	cout << "Tong: " << sp1 + sp2 << endl;
	cout << "Hieu: " << sp1 - sp2 << endl;
	cout << "Tich: " << sp1 * sp2 << endl;
	cout << "Thuong: " << sp1 / sp2 << endl;
	return 0;

}