#include <iostream>
using namespace std;
void Nhapmang(int a[100], int &n)
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
}
void sole(int a[100], int n)
{
    for (int i=0;i<n;i++)
    if (i%2!=0) cout << a[i] << " ";
}
int main()
{
    int n, a[100];
	Nhapmang(a, n);
	sole(a,n);
}
