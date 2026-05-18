#include "Bo.h"
#include "Cuu.h"
#include "De.h"
#include <ctime>

int main() {
    srand((unsigned int)time(NULL));

    int nBo, nCuu, nDe;
    cout << "Nhap so luong Bo ban dau: ";
    cin >> nBo;
    cout << "Nhap so luong Cuu ban dau: ";
    cin >> nCuu;
    cout << "Nhap so luong De ban dau: ";
    cin >> nDe;

    int tongGiaSuc = nBo + nCuu + nDe;
    GiaSuc** ds = new GiaSuc * [tongGiaSuc];

    int index = 0;
    for (int i = 0; i < nBo; i++) {
        ds[index++] = new Bo();
    }
    for (int i = 0; i < nCuu; i++) {
        ds[index++] = new Cuu();
    }
    for (int i = 0; i < nDe; i++) {
        ds[index++] = new De();
    }

    cout << "\n--- TIENG KEU KHI GIA SUC DOI ---" << endl;
    for (int i = 0; i < tongGiaSuc; i++) {
        ds[i]->Keu();
    }
    cout << endl;

    int tongBo = nBo;
    int tongCuu = nCuu;
    int tongDe = nDe;
    int tongSua = 0;

    for (int i = 0; i < tongGiaSuc; i++) {
        int loai = ds[i]->GetLoai();
        int soCon = ds[i]->SinhCon();
        int soSua = ds[i]->ChoSua();

        if (loai == 1) tongBo += soCon;
        else if (loai == 2) tongCuu += soCon;
        else if (loai == 3) tongDe += soCon;

        tongSua += soSua;
    }

    cout << "\n--- THONG KE SAU MOT LUA SINH VA CHO SUA ---" << endl;
    cout << "Tong so Bo hien tai: " << tongBo << endl;
    cout << "Tong so Cuu hien tai: " << tongCuu << endl;
    cout << "Tong so De hien tai: " << tongDe << endl;
    cout << "Tong so lit sua thu duoc: " << tongSua << " lit" << endl;

    for (int i = 0; i < tongGiaSuc; i++) {
        delete ds[i];
    }
    delete[] ds;

    return 0;
}