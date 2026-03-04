#include <iostream>

using namespace std;

int main()
{
    int n, a[100],x,k;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> x >> k;
    for (int i=n;i>k;i--)
        a[i] = a[i-1];
    a[k] = x;
    n++;
    for (int i=0; i<n;i++)
        cout << a[i] << " ";
    return 0;
}
