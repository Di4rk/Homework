#pragma once
#include <iostream>
using namespace std;

struct Diem {
	float x;
	float y;
};

class cTamGiac {
private:
	Diem a, b, c;
	float KhoangCach(Diem p1, Diem p2);
public:
	cTamGiac();
	friend istream& operator>>(istream& is, cTamGiac& tg);
	friend ostream& operator<<(ostream& os, cTamGiac tg);
	
	void KiemTra();
	float ChuVi();
	float DienTich();
	
	void Quay(float goc);
	void TinhTien(float dx, float dy);
	void PhongTo(float heso);
	void ThuNho(float heso);
};