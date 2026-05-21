#include "DanhSachSV"

int main() {
	DanhSachSV ds;
	ds.Nhap();
	ds.XuatSVTotNghiep();
	ds.XuatSVKoTotNghiep();

	cout << "Sinh vien dai hoc co diem trung binh cao nhat: \n";
	ds.SVDaiHocCoDiemTrungBinhCaoNhat()->Xuat();

	cout << "Sinh vien cao dang co diem trung binh cao nhat: \n";
	ds.SVCaoDangCoDiemTrungBinhCaoNhat()->Xuat();

	ds.SoLuongSVKoTotNghiepTheoLoai();
}