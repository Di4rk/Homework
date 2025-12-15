#include <bits/stdc++.h>
int gcd(int m,int n)
{
    if(n>m)
    {
        int a=m;
        m=n;
        n=a;
    }
    while(n!=0)
    {
        int r=m%n;
        m=n;
        n=r;
    }
    return m;
}
void input(int &n)
{
    cin >> n;
}
int input()
{
    int m;
    cin >> m;
    return m;
}
}
int main() {
	int m, n;
	input(n);
	m=input();
	cout << gcd(m, n);
}

