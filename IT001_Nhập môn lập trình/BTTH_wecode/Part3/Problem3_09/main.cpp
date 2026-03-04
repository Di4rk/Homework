#include <iostream>

using namespace std;
int ktsnt(int n)
{
    if (n==1) return -1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0 && i>1) return 0;
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    cout << ktsnt(n);
}
