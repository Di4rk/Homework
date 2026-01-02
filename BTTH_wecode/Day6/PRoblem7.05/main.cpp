#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    float a[100][100], S=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
                if(i==j)
                    S+=a[i][j];
            }
    cout << S;
    return 0;
}