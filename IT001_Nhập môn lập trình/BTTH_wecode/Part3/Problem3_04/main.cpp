#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    long double S=0;
    cin >> n;
    float t=1.0;
    for (int i=0;i<=n;i++)
    {
        if (i%2==0) t=1.0;
        else t=-1.0;
        S+= t/(i*2+1);
    }
    cout << 4*S;
    return 0;
}
