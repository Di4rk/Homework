#include <bits/stdc++.h>

using namespace std;
long double tong1(int n)
{
    long double S=0;
    for (int i= 1;i<=n;i++)
        S+= pow(i,i);
    return S;
}
long double tong2(int n)
{
    long double S=0,t=1;
    for (int i= 1;i<=n;i++)
    {
        if (i>0) t*=i;
        S+=t;
    }
    return S;
}
long double tong3(int n)
{
    long double S=0, T=0;
    for (int i= 1;i<=n;i++)
    {
        T+=i;
        S+=1.0/T;
    }
    return S;
}
int main()
{
    unsigned int n;
    cin >> n;
    cout << tong1(n) << endl << tong2(n) <<endl <<tong3(n);
    return 0;
}
