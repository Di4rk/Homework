#include <bits/stdc++.h>

using namespace std;
long long fib(int n)
{
    if (n==0||n==1) return 1;
    return (n*fib(n-2));
}
int main()
{
    int n;
    cin >> n;
    cout << fib(n);
}
