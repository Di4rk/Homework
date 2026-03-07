#include <iostream>
class PhanSo {
private: 
    int Tu, Mau;
public:
    void Nhap() {
		cout << "Nhap tu so: ";
		cin >> Tu;
		cout << "Nhap mau so: ";
		cin >> Mau;
    }
	void Xuat() {
		cout << "Phan so: " << Tu << "/" << Mau << endl;
	}
};
int main()
{
    std::cout << "Hello World!\n";
}