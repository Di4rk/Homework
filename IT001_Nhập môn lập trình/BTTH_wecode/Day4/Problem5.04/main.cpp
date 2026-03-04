#include <iostream>

using namespace std;
bool ktrasnt(int n)
{
    if(n<2) return false;
    for(int j=2;j*j<=n;j++)
        if(n%j==0) return false;
    return true;
}
int daoso(int n)
{
    int i=0;
    for (;n!=0;n/=10)
        i=i*10+n%10;
    return i;
}
int main()
{
    int a,b,j=0;
    cin >> a >> b;
    for(int i=a; i<=b; i++)
        if(ktrasnt(i) && ktrasnt(daoso(i)))  j++;
    cout << j;

}
