#include <bits/stdc++.h>
using namespace std;
void NhapMaTran(float a[100][100], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
}
void XuatMaTran(float a[100][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int m,n;
    cin >> m >> n;
    float a[100][100];
    NhapMaTran(a, m, n);
    XuatMaTran(a, m, n);
    return 0;
}
