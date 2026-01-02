#include <iostream>
using namespace std;



void horizontal_invert(int a[][1000], int n, int m)
{
    int dem=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {            
            int temp = a[i][j];
            a[i][j] = a[n-1-i][m-1-j];
            a[n-1-i][m-1-j] = temp;
            dem++;
            if (dem >= (m*n)/2) return;
        }
    }
}
void input(int a[][1000], int n, int m)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
}
void output(int a[][1000], int n, int m)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cout << a[i][j];
}

int main()
{
    int n, m;
    cin >> n >> m;

    
    int a[1000][1000];
    
    input(a, n, m); //Hàm này đã được code chuẩn không thể chỉnh, sinh viên không cần quan tâm
    
    horizontal_invert(a, n, m);

    output(a, n, m);//Hàm này đã được code chuẩn không cần chỉnh, sinh viên không cần quan tâm
    
    return 0;
}
