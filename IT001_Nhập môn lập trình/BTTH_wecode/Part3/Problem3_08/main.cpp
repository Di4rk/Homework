#include <iostream>
using namespace std;
int main()
{

    long n,S=0;
    cin >> n;
    for (int i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            if(i!=n/i) S+= n/i;
            S+=i;
        }
    }
    cout << S-n;
}
