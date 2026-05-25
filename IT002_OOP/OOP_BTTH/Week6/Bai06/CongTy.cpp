#include "CongTy.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

void CongTy::xuLyDuLieu(const string& fileINP, const string& fileOUT) {
	ifstream in(fileINP);
	if (!in) {
		cout << "Loi: khong the mo file " << fileINP << "!\n";
		return;	
	}

	
	in >> x >> y >> z;
	for(int i = 0; i < x; i ++) {
		KhachHang* a = new KhachBTH();
		a->Nhap();
		dsKhachBTH.push_back((KhachBTH*)a);
	}
	for (int i = 0; i < y; i++) {
		KhachHang* a = new KhachThan();
		a->Nhap();
		dsKhachThan.push_back((KhachThan*)a);
	}

	for (int i = 0; i < z; i++) {
		KhachHang* a = new KhachVIP();
		a->Nhap();
		dsKhachVIP.push_back((KhachVIP*)a);
	}
	in.close();

	ofstream out(fileOUT);
	
	out << fixed << setprecision(0);
	out << x << " " << y << " " << z << endl;
	double Tongdoanhthu = 0;
	auto ghiDanhSach = [&](const vector<KhachHang*>& ds) {
		for (const auto& kh : ds) {
			kh->Xuat();
			Tongdoanhthu += kh->ThanhTien();
		}
		};

	ghiDanhSach(dsKhachBTH);
	ghiDanhSach(dsKhachThan);
	ghiDanhSach(dsKhachVIP);

	out << "Tong doanh thu: " << Tongdoanhthu << endl;
	out.close();

	cout << "Xuat file " << fileOUT << " thanh cong!\n";

}

CongTy::~CongTy() {
	for (auto kh : dsKhachBTH) delete kh;
	for (auto kh : dsKhachThan) delete kh;
	for (auto kh : dsKhachVIP) delete kh;
}
