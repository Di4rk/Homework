
#include <iostream>
using namespace std;
#define MAXR 100
#define MAXC 100

void NhapMaTran(float X[][MAXC], int m, int n);
void XuatMaTran(float X[][MAXC], int m, int n);
void ChuyenViMaTran(float X[][MAXC], float Y[][MAXR], int m, int n);


int main() {
    int m, n; cin >> m >> n;
    float a[MAXR][MAXC], b[MAXC][MAXR];
    NhapMaTran(a, m, n); // Ma trận a có kích thước là m x n
    ChuyenViMaTran(a, b, m, n);
    XuatMaTran(b, n, m); // Khi chuyển vị ma trận a thu được ma trận b có kích thước n x m
    return 0;
}

void NhapMaTran(float X[][MAXC], int m, int n) 
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> X[i][j];
}
void XuatMaTran(float X[][MAXC], int m, int n) 
{
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++)
            cout << X[i][j] << " ";
        cout << endl;
    }
}
void ChuyenViMaTran(float X[][MAXC], float Y[][MAXR], int m, int n) 
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            Y[j][i] = X[i][j];
}