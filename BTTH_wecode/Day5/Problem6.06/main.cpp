#include <iostream>

using namespace std;

int main()
{
    int a[100],n,dem=0;
    cin >> n;
    for (int i =0;i<n;i++)
        cin >> a[i];
    int maxx =a[0];
    for(int i=0;i<n;i++)
        if(a[i] > maxx ) maxx = a[i];
    for (int i=0;i<n;i++)
        if(a[i]==maxx) dem++;
    cout << maxx << "\n" << dem;
}
