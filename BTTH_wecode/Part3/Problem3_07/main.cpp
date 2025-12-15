#include <iostream>

using namespace std;

int main()
{
    int n,a,b;
    long S=0;
    cin >> a >> b >> n;
    for (int i=1;i<=n;i++)
    {
        S+= a*b;
        a++;
        b++;
    }
    cout << S;
}
