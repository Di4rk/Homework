#include <iostream>

using namespace std;

int main()
{
    int n, a[100], p,k;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cin >> p >> k;

    for(int i=1;i<=k;i++)
    {
        for(;p<n;p++)
        {
            a[p] = a[p+k];
        }
        n--;
    }
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
}
