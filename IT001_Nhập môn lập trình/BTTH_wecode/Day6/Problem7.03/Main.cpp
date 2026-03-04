#include <bits/stdc++.h>
using namespace std;
#define MAXR 16
#define MAXC 16
void NhapMaTran(int a[MAXR][MAXC], int &n) 
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
}
bool isMaTranDonVi(int a[MAXR][MAXC], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            {
                if (i == j) 
                {
                    if (a[i][j] != 1) return false;
                } 
                else 
                {
                    if (a[i][j] != 0) return false;
                }
            }
    return true;
}
int main() {
    int a[MAXR][MAXC], n;
    NhapMaTran(a, n);
    std::cout <<  std::boolalpha << isMaTranDonVi(a, n);
    return 0;
}
