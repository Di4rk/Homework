#include <iostream>
#include <string>
using namespace std;
class HocSinh {
private:
    string maHS, hoTen;
    float diemToan, diemVan;
public:
    void nhap() {
        cout << "Nhap ma HS: "; cin >> maHS;
        cin.ignore();
        cout << "Nhap ho ten: "; getline(cin, hoTen);
        cout << "Nhap diem Toan, Van: "; cin >> diemToan >> diemVan;
    }
    void xuat() {
        cout << maHS << " - " << hoTen << " | Toan: " << diemToan << " | Van: " << diemVan << " | DTB: " << tinhDTB() << "\n";
    }
    float tinhDTB() {
        return (diemToan + diemVan) / 2.0;
    }
};
int main() {
    HocSinh hs1, hs2;
    cout << "Nhap hs1: \n"; hs1.nhap();
    cout << "Nhap hs2: \n"; hs2.nhap();
    cout << "\n=> Hoc sinh co DTB lon hon la:\n";
    if (hs1.tinhDTB() > hs2.tinhDTB()) hs1.xuat();
    else if (hs1.tinhDTB() < hs2.tinhDTB()) hs2.xuat();
    else {
        cout << "Hai hoc sinh co DTB bang nhau:\n";
        hs1.xuat(); hs2.xuat();
    }
    return 0;
}