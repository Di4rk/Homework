#include <bits/stdc++.h>
using namespace std;
bool KiemTraMaTranFrobenius(float a[100][100], int n)
{
    int Check=0;
    for (int j=0;j<n;j++)
    {
        bool ok=true;
        for (int i=0;i<n;i++)
        {
            if (j > i && a[i][j] != 0)
                return false;
            if (j == i && a[i][j] != 1)
                return false;
            if (j < i) if (a[i][j] != 0) 
            {
                Check++;
                break;
            }
        }
    }
    if (Check>1)
        return false;
    return true;
}
int main()
{
    int n,m;
    cin >> n >> m;
    if (n != m)
    {
        cout << "No";
        return 0;
    }
    float a[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    if (KiemTraMaTranFrobenius(a, n)) cout << "Yes";
    else cout << "No";
    return 0;
}