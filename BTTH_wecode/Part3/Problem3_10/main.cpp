#include <iostream>

using namespace std;
long Fibonacci(int x)
{
    if (x==1) return 1;
    if (x==0) return 0;
    long S=0;
    S = Fibonacci(x-1) + Fibonacci(x-2);
    return S;
}
int main()
{
    int x;
    cin >> x;
    if ( x >= 1 && x<=30) cout << Fibonacci(x);
    else cout << "So " << x << " khong nam trong khoang [1,30].";
    return 0;
}
