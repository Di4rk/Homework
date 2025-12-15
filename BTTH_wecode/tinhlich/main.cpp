#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    long k,p,q, vitriA, vitriB, deA;
    cin >> n >> k >> p >> q;
    vitriA = (p-1)*2 + q;
    if ( vitriA + k > n) cout << "-1";
    else if ( vitriA + k <= n && vitriA - k >= 1)
    {
        if (abs(vitriA - k) < abs(vitriA + k)) vitriB = vitriA -k;
        else vitriB = vitriA+k;
    }
    else if (vitriA + k <= n) vitriB = vitriA +k;
    else vitriB = vitriA - k;
    if ( vitriA + k <= n)
    {
        cout << (vitriB + 1) /2 << " " << ((vitriB % 2 == 1) ? 1 : 2);
    }
}
