#include <iostream>

using namespace std;

int Input()
{
    int n;
    cin >> n;
    return n;
}
long sum_even_devisor(int n)
{
    long S=0;
    for(int i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            if (i!=n/i && (n/i)%2==0) S+=n/i;
            if (i%2==0) S+= i;
        }
    }
    if(S==0) return -1;
    return S;
}
int main()
{
    int n;
    n=Input();
    cout << sum_even_devisor(n);
}
