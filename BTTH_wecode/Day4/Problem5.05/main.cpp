#include <iostream>

using namespace std;
void input(int &n)
{
    cin >> n;
}
int sum(int n, int &s)
{
    if(n==0) return 0;
    s = n%10 + sum(n/10,s);
    return s;
}
int main() {
    int n, s=0;
    input(n);
    sum(n, s);
    cout << s;
}
