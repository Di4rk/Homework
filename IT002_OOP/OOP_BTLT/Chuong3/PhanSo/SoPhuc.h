#pragma once
class SoPhuc {
	private:
	double thuc;
	double ao;
public:
	void Nhap() {
		std::cout << "Nhap phan thuc: ";
		std::cin >> thuc;
		std::cout << "Nhap phan ao: ";
		std::cin >> ao;
	}
	void Xuat() {
		std::cout << "So phuc: " << thuc << " + " << ao << "i" << std::endl;
	}
	void Cong(SoPhuc sp) {
		double thucTong = thuc + sp.thuc;
		double aoTong = ao + sp.ao;
		std::cout << "Tong: " << thucTong << " + " << aoTong << "i" << std::endl;
	}

};