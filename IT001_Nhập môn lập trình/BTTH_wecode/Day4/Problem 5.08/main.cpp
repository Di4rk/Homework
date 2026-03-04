#include <iostream>

using namespace std;

int reverse(int n, int i=0)
{
    if(n==0) return i;
    return reverse(n/10, i*10 + n%10);
}

int main() {
    int n;
    cin >> n;
    cout << reverse(n);
}
