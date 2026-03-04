#include <iostream>

using namespace std;

int main()
{
    int n, a[100], lon=0, lon2=0;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]>lon) lon = a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i] == lon) a[i]=0;
    }
    for (int i=0;i<n;i++)
    {
        if (a[i]>lon2) lon2=a[i];
    }
    cout << lon2;
}
