#include <iostream>
#include "CMatrix.h"

using namespace std;

int main() {
    cout << "TEST MA TRAN X VECTOR\n";
    CMatrix A;
    cout << "Nhap ma tran A:\n";
    cin >> A;

    CVector v;
    cout << "\nNhap vector V:\n";
    cin >> v;

    cout << "\nMa tran A:\n" << A;
    cout << "Vector V: " << v << "\n";

    CVector result_Av = A * v;
    cout << "=> A * V = " << result_Av << "\n\n";

    cout << "TEST MA TRAN X MA TRAN\n";
    CMatrix B;
    cout << "Nhap ma tran B de nhan voi A:\n";
    cin >> B;

    cout << "\nMa tran B:\n" << B;

    CMatrix result_AB = A * B;
    cout << "=> A * B:\n" << result_AB << "\n";

    system("pause");
    return 0;
}