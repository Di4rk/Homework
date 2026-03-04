#include <iostream>
#include <math.h>
using namespace std;
bool kiemtra(int k)
{
    if(k<2) return false;
    for(int i=2;i*i<=k;i++)
        if(k%i==0)return false;
    return true;
}
int songuyento(int n)
{
    int i=0,S=0;
    for (int k=1;i!=n;k++)
    {
        if(kiemtra(k))
        {
            S+=k;
            i++;
        }
    }
    return S;
}
int main()
{
    int n;
    do {
        cin >> n;
        if (n <= 0 || n > 50)
            cout << "Gia tri vua nhap la " << n << ", khong hop le. Vui long nhap lai.\n";
    } while (n <= 0 || n > 50);
    cout << "Tong " << n << " so nguyen to dau tien la: " << songuyento(n);
}
