#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,l,k;
    float A[100][100], B[100][100];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    cin >> l >> k;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < k; j++)
            cin >> B[i][j];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++) 
        {
            cout << A[i][j] + B[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}