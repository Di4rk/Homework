#include "CongTy.h"
#include "NVSanXuat.h"
#include "NVVanPhong.h"

using namespace std;

int main() {
	DanhSachNhanVien dsnv;
	dsnv.Nhap();

	cout << "Tien luong va thong tin cua tung nhan vien: " << endl;
	dsnv.Xuat();

	cout << "Tong luong cong ty phai tra: " << dsnv.TongLuong() << endl;

	dsnv.LuongThapNhat();

	cout << "Nhan vien van phong co tuoi cao nhat: " << endl;
	dsnv.TuoiCaoNhat();
}