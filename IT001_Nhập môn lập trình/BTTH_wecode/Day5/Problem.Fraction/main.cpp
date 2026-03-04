#include <bits/stdc++.h>

using namespace std;
long long GCD(long long a,long long b)
{
    if (b==0) return a;
    return GCD(b,a%b);
}
int main()
{
    long long a,b,c,d,Dem = 0;
    cin >> a >> b>> c>> d;
    if (a*d >= b*c)
    {
        cout << Dem;
        return 0;
    }
    while(a*d<b*c)
    {
        a++;
        b++;
        int uocchung = GCD(a,b);
        a/= uocchung;
        b/= uocchung;
        Dem++;
        if (a==c && b==d)
        {
            cout << Dem;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
