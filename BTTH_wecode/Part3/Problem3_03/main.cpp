#include <iostream>

using namespace std;

int main()
{
    int n,i=0;
    cin >> n;
    for (;n>0;n/=10)
        i+=n%10;
    cout << i;
}
