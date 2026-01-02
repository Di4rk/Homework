#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    float a[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j=0; j<m; j ++)
            if (i != j) if(a[i][j] != 0) {cout << "No";  return 0;}
    }
    cout << "Yes";
    return 0;
}