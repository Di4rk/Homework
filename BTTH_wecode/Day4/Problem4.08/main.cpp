#include <iostream>
using namespace std;


int reverse(int n)
{
    int i=0;
    for(; n!=0; n/=10)
        i=i*10 + n%10;
    return i;
}


int main()
{
	int n;
	cin >> n;
    cout << reverse(n);
}


