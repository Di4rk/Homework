#include <bits/stdc++.h>

using namespace std;
long long tinhsolan(long long n, long long m, long long h, long long w)
{
    if(n<=h && m<=w) return 0;
    long long DaiG= max(n,m), RongG= min(n,m), DaiB=max(h,w), RongB=min(h,w);
    if(DaiG > DaiB) return 1+ tinhsolan(DaiG/2,RongG,DaiB,RongB);
    else return 1+ tinhsolan(DaiG,RongG/2,DaiB,RongB);
}
int main()
{
    long long n,m,h,w;
    cin >> n>>m>>h>>w;
    cout <<  tinhsolan(n,m,h,w);
    return 0;
}
