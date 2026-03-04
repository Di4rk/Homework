#include <bits/stdc++.h>

using namespace std;
bool ktsnt(int n);
int main()
{
    int n;
    cin >> n;
    int j=0;
    for(int i =2;i<n-2;i++)
        if (ktsnt(i) && ktsnt(i+2))
        {
            j++;
            cout << i << ", " << i+2 << endl;
        }
    cout << "Tong: " << j << " cap so sinh doi < " << n;
}
bool ktsnt(int n)
{
    if (n<2) return false;
    for(int i=2; i*i<=n;i++)
        if (n%i==0) return false;
    return true;
}

