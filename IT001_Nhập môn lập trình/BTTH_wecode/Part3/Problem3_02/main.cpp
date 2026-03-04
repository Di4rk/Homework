#include <bits/stdc++.h>

using namespace std;
bool ktdx(int n)
{
    int a = n,i=0;
    if (n==0) return true;
    for (;n>0;n/=10)
        i = i*10 + n%10;
    if (i-a == 0) return true;
    else return false;
}
int main()
{
    int n;
    cin>>n;
    cout << boolalpha << ktdx(n);
}
