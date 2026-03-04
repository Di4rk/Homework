#pragma once
class PhanSo {
private:
	int tu;
	int mau;
	int UCLN(int a, int b);
public:
	PhanSo();
	PhanSo(int tu, int mau);
	void Nhap();
	void Xuat();
	void RutGon();
	PhanSo Cong(PhanSo psKhac);
};