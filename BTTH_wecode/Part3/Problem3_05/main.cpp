#include <bits/stdc++.h>

using namespace std;
long double tong1(int n, int x)
{
    long double S=0, t=1;
    for (int i= 0;i<=n;i++)
    {
        if (i>0) t*=x;
        S+= t;
    }
    return S;
}
long double tong2(int n, int x)
{
    long double S=0,t=1;
    for (int i= 0;i<=n;i++)
    {
        if (i>0) t*=x*x;
        S+= t;
    }
    return S;
}
long double tong3(int n, int x)
{
    long double S=0, T=1;
    for (int i= 0;i<=n;i++)
    {
        S+= T;
        T = T*x/(long double)(i+1);
    }
    return S;
}
int main()
{
    unsigned int n,x;
    cin >> n >> x;
    cout << tong1(n,x) << endl << tong2(n,x) <<endl <<tong3(n,x);
    return 0;
}
