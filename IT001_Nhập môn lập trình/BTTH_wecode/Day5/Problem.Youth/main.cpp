#include <bits/stdc++.h>

using namespace std;
string Nhap(string &n)
{
    cin >> n;
    return n;
}
void KiemTraDoTre(string n)
{
    int Dem = 0,Canh=0;
    for(int i = size(n); i>=0;i--)
    {
        if (n[i]>'0') Canh = '1';
        if (n[i]<Canh) Dem++;
    }
    cout << Dem;
}
int main()
{
    string n;
    Nhap(n);
    KiemTraDoTre(n);
}
