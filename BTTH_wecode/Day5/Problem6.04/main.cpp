#include <iostream>

using namespace std;
bool kiemtra(int j)
{
    if (j<2) return false;
    for(int i=2;i*i<=j;i++)
    {
        if(j%i==0) return false;
    }
    return true;
}
int main()
{
    int n, b=0, a[100];
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
        if(kiemtra(a[i]))
        {
            cout << a[i] << " ";
            b++;
        }
    }
    if (b==0) cout << b;
    return 0;
}
